/*******************************************************************************

*Project: Tutorial week 2

*Objection: 1. Learning how to describe and manipulate data;
            2. Learning some basic visualization methods.
			  
*******************************************************************************/

clear all 
cap log close // close possible prior log file

cd "/Users/yolandayang/Desktop/3121/Tutorial 2" // change it to your own workplace
log using "week2.log", replace

*=======================1.Describe and manipulate data=========================*

****1.1 load data****
use aghousehold, clear

****1.2 describe data and rename variables****
/*data  type (help data_types)
str: 
descirbe information like name, id or address;
just as identity, cannot be calculated;
it's capital-sensitive, always noted by quotations

date: 
%tc、%td、%tw、%tm、%tq、%th、%tg; 
help date
    Otherwise, try substr()

numeric:  classified by precision/accuracy
byte: [-127, 100]
int: integer
long: long integer

float or double: high precision
*/
//describe i.e. variable names, storage type, display format, label
describe 
describe nh7_1
describe, fullnames
describe, short

//summarize i.e. mean, std, min, max 
sum
sum nh7_1

//tabulate frequencies you can tab oneway, twoway or tab, summarize()
tab sm
tab nh7_1 if nh7_1<1

//Rename
rename hh_id household_id
rename h86_a015 educ_lvl
rename nh1a_8 gov_emp_num
rename nh1a_9 cadre_num
rename hx95_nh16 perm_resi_num
rename hx95_nh17 perm_resi_rural_num

rename nh3_1 tv_asset
rename nh7_1 total_income
rename nh7_25 total_expense
rename nh7_40 exp_consump
rename nh7_43 exp_consump_food
rename nh7_48 exp_consump_clothing
rename nh7_49 exp_consump_housing
rename nh7_70 net_income
rename nh7_72 cash_inhand

rename hx95_nh111 sown_area
rename hx95_nh112 sown_area_crop

rename nh6_3 fert_quant
rename nh6_5 fert_value

****1.3 create, keep & drop and label variables****
gen test=1 //always apply to simple operation
// create an indicator(dummy) for year 1995
gen x=1 if year==1995
replace x=0 if x!=1 //or year!=1995


recode gov_emp_num (1=2) (0=1), gen(gov_emp_num_plus_one)
recode gov_emp_num_plus_one (1=0) (2=1), gen(gov_emp_num_minus_one)
recode total_income (min/20000 = 0) (20001/max = 1), gen(income_Dummy)
*this indicates RANGE. 
*If the income is less than 20000, we label it 0;
*If the income is greater than 20000, we label it 1.

//related to function; help egen
egen rmin = rowmin( exp_consump_food exp_consump_clothing exp_consump_housing )	

/*drop and keep are not reversible. You would need to go back to the original dataset and read it in again.
Instead of applying drop or keep for a subset analysis, consider using if or in to select subsets
temporarily. 
Alternatively, applying preserve followed in due course by restore may be a good approach.*/
rename x year_1995	
*keep if year_1995==1 //cannot be recalled 
*drop if year_1995==1
*drop in 1/64
*drop in -64/-1

drop if total_income<=0
drop if total_expense<=0
drop if fert_quant<=0

//Tabulate missing values
misstable summarize
drop if missing(total_income)
drop if missing(total_expense)
drop if missing(fert_quant)
drop if missing(fert_value)

//Labelling
//1. define a rule for cardinal numbers
label define income_level 0 "low income" 1 "high income"
//2. apply it to the variable
label values income_Dummy income_level

/*Question: 
gen income_dummy = "low income" if income_Dummy ==0 
replace income_dummy = "high income" if income_Dummy ==1
*/

****1.4 transform data****
//logarithm transforming
gen total_income_log=log(total_income)
gen total_expense_log=log(total_expense)
gen fert_value_log=log(fert_value)

/*recast string to an integer (or other types); this command can be used to convert 
the target date into a specific type*/
recast int household_id

//numeric to string
tostring household_id, generate(hh_id_string)
tostring household_id, replace //make change to the orginal variable

//string(consist of numbers) to numeric
destring household_id, replace 
*destring household_id, gen(hh_id1) // or generate a new variable

//column ordering
order total_income_log, before(tv_asset) //change the sequence of variable displayed
order total_income_log, first
order total_income_log, last
order total_income_log, after(tv_asset)
order total_expense_log, after(total_income_log)
order fert_value_log, after(fert_value)


*==============================2.Visualization=================================*

****2.1 visualization of single variable****
*box plot and  hist plot*
graph box total_income, name(income_box)
graph box total_income_log, name(log_income_box)
hist total_income, name(income_hist)
hist total_income_log, normal

graph box fert_value_log
hist fert_value_log

****2.2 visualization of two variables***** twoway plot [if] [in] [, twoway_options]）
*twoway plot y x
preserve
collapse (mean) fert_value_log, by(year)
list
twoway line fert_value_log year //line plot
twoway connected fert_value year //line plot with points
restore

twoway scatter total_expense_log total_income_log // scatter plot
twoway dropline total_expense_log total_income_log // dropline plot
twoway spike total_expense_log total_income_log //spike plot
//twoway lowess total_expense_log year //locally weighted scatterplot smoothing

****2.3 visualization of multi variables***** graph twoway plot yvar1 yvar2 yvar3 … xvar
twoway scatter total_expense_log total_income_log year
twoway (scatter total_expense_log total_income_log), by(year)
//twoway area total_expense_log total_income_log year

log close
