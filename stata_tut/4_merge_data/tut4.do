clear all
cd "~/Desktop/data"

* MERGE DATASET *

* one-to-one merge
** loading the main dataset, example_1.dta
use merge_ex_1.dta, clear
** sorting the key variable
sort hh_id

** checking the additional dataset, example_2.dta
use merge_ex_2.dta, clear
** extracting the first four digits of string variable hh_id
replace hh_id=substr(hh_id, 1, 4)
** sorting the key variable
sort hh_id

** this is 1-1 merge, the order of loading dataset doesn't matter
** now in memory, example_2.dta is prior to example_1.dta, hence we need to put 
** example_1.dta after using option
merge 1:1 hh_id using merge_ex_1.dta

*____________________________________*

* many-to-one merge
clear all

** loading the main dataset, example_1.dta
use merge_ex_1.dta, clear
** sorting the key variable
sort country

** checking the additional dataset, example_3.dta
use merge_ex_3.dta, clear
** sorting the key variable
sort country

** this is many-to-one merge, the order of loading dataset matters!
** now example_3.dta in memory, it is prior to example_1.dta, hence we need to use 
** option 1:m, and put example_1.dta after using option
merge 1:m country using merge_ex_1.dta

** optional: if we do not check the additional dataset, after loading the main 
** dataset, example_1.dta, we need to use
* use merge_ex_1.dta, clear
* merge m:1 country using merge_ex_3.dta

* order the column
order hh_id
* drop observations containing missing data for column hh_id, log_income and educ
drop if missing(hh_id, log_income, educ) 

save merged_ex.dta
*____________________________________*

* IV REGRESSION *
use https://www.stata-press.com/data/r18/hsng

* 2SLS - first stage
reg hsngval pcturban faminc i.region
predict valhat, xb

* 2SLS - second stage
reg rent valhat pcturban

* ivregress
ivregress 2sls rent pcturban (hsngval = faminc i.region)
