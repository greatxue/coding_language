/* set work direction and import data */
clear all 
cd "/Users/yolandayang/Desktop" 
use aghousehold, clear

/* install outreg2 to export excel format of our regression result */
ssc install outreg2

**** Goal: analyze the effect of education of head on total income

/* 1. limit the sample to households in year 2002: sort out the cross-sectional data we want */
keep if year == 2000

/* 2. run the simple linear regression: annual income as dependent variable and level of education as explanatory variable */
reg nh7_1 h86_a015
outreg2 using reg_withoutlog.xls, excel label
reg nh7_1 h86_a015, robust  // regression without outliers(control for heteroskedasticity)
outreg2 using reg_withoutlog.xls, excel label


/* 3. log-linear relationship: interpretating education level and percent change in annual income */
gen ln_income = log(nh7_1 + 1)
reg ln_income h86_a015
outreg2 using reg_rescale.xls, excel label replace
* outreg2 using reg_rescale.xls, excel label append
* outreg2 using reg_rescale.xls, excel label replace

/* 4. compute the predicted/fitted value of log(income) */
predict hat_ln_income 
predict resid_ln_income, residuals

/* 5. test for coefficient (Test linear hypotheses after estimation) */
test h86_a015 = 0
test h86_a015 = 0.15

