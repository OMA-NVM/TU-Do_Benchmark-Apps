#!/bin/bash

cd $1
rm -rf build ; kraft build
mkdir /workspaces/BenchGem5NVMain/simulations/$1-$2.d
cp build/helloworld_gem5-arm64.dbg /workspaces/BenchGem5NVMain/simulations/$1-$2.d/$1-$2.dbg


#MIN=$(nm $1 | grep "approdata_start" | sed 's/ .*//' | sed 's/.[8]//')
#MAX=$(nm $1 | grep "heap_end" | sed 's/ .*//' | sed 's/.[8]//')


#MINStack=$(nm $1 | grep "appstack_start" | sed 's/ .*//' | sed 's/.[8]//')
#MAXStack=$(nm $1 | grep "appstack_end" | sed 's/ .*//' | sed 's/.[8]//')


cd  /workspaces/BenchGem5NVMain/simulations/$1-$2.d
cp ../printtrace.config.parse printtrace.config.parse

export M5_PATH=.
/workspaces/BenchGem5NVMain/gem5/build/ARM/gem5.fast /workspaces/BenchGem5NVMain/gem5/configs/example/fs.py \
	--bare-metal --disk-image /workspaces/BenchGem5NVMain/simulations/fake.iso \
	--kernel=/workspaces/BenchGem5NVMain/simulations/$1-$2.d/$1-$2.dbg \
	--mem-type=NVMainMemory \
	--nvmain-config=printtrace.config.parse \
	--cpu-type=DerivO3CPU --machine-type=VExpress_GEM5_V2 --caches --l2cache \
	--l1i_size='32kB' --l1d_size='8kB' --l2_size='8kB' --dtb-filename=none \
	--mem-size=4GB > gem5.terminal #--param 'system.cpu[0].wait_for_remote_gdb = True'


#cat gem5.terminal | grep "simulation_cycles" > MemCycles.txt
#cat gem5.terminal | grep "totalWriteRequests" >> MemCycles.txt
#cat gem5.terminal | grep "totalReadRequests" >> MemCycles.txt

#echo "${MIN}"
#echo "${MAX}"
#Rscript ../analysis/plot.R 0x$MIN  0x$MAX
#mv plot.pdf $1.pdf
#Rscript ../analysis/plot.R 0x$MINStack  0x$MAXStack
#mv plot.pdf $1-Stack.pdf
#Rscript ../analysis/plot.R 0x$MIN  0x$MINStack
#mv plot.pdf $1-All.pdf