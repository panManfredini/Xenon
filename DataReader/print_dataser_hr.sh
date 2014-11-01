cat run_12_datasets_livetime | gawk '{print  "case \""$1 "\" : \n\t live_time = " $9 "; \n\t break;"}' > out_test 
