*****************************
********Tutorial1************
*****************************


clear //clear dataset
cap log close // close possible prior log file
* log close is enough, but the program will display error if no log file is runnning.
* Maybe, cap loc close is better to prevent error.


******** Create a log file************
cd "/Users/yolandayang/Desktop/3121/tut1"  // define a path 
log using 3121_tut1.log, replace // log file is used to record both command and output.


******** Import data ************

/*excel file*/
import excel "auto.xlsx", sheet("Sheet1") firstrow clear


/*csv file*/
insheet using /Users/yolandayang/Desktop/auto.csv, clear 

/*dta file*/
use auto, clear 


cap log close
