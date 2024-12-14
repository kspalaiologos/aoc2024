#!/usr/bin/env bash
make clean >/dev/null && make DEBUG=0 -j$(nproc) 2>/dev/null >/dev/null
if [ $? -ne 0 ]; then
  echo -e "\033[1;31mCompilation failed\033[0m"
  exit 1
fi
function day {
  d=$1 ; out=$2
  "./d$d.out" | head -n 1 | grep -q "$out"
  if [ $? -eq 0 ]; then
    echo -e "\033[1;32mDay $d: passed\033[0m"
  else
    echo -e "\033[1;31mDay $d: failed\033[0m"
    exit 1
  fi
}
day "01" "T1: 1603498, T2: 25574739"
day "02" "T1: 479, T2: 531"
day "03" "T1: 185797128, T2: 89798695"
day "04" "T1: 2718, T2: 2046"
day "05" "T1: 5064, T2: 5152"
day "06" "T1: 5212, T2: 1767"
day "07" "T1: 303876485655, T2: 146111650210682"
day "08" "T1: 244, T2: 912"
day "09" "T1: 6344673854800, T2: 6360363199987"
day "10" "T1: 646, T2: 1494"
day "11" "T1: 194782, T2: 233007586663131"
day "12" "T1: 1381056, T2: 834828"
day "13" "T1: 28059, T2: 102255878088512"
day "14" "T1: 231852216, T2: 8159"
exit 0
