#!/bin/bash
#
#	auto create(svn co) projects
#
#	author : bdepwgjqet
#
#	param [number of project] [[project name] [project svn path] ...]
#

function create_project () 
{
	HOME_PATH="/home/yonghong.yyh/d/workspace/eclipse/tmall-seller"

	cd $HOME_PATH

	if [ ! -d '$HOME_PATH"/"$1' ]; then
		rm -r $1
	fi

	mkdir $1

	cd $1

	svn co $2

	cd `ls`

	cd `ls`

	svn up

	mvn eclipse:clean

 	mvn -Declipse.downloadSources=true eclipse:eclipse
}

NUM=$#

for (( i=1; i<=$NUM; i++ )); do
	param[$i]=$1
	shift
done

N=${param[1]}

if [ $[$N * 2 + 1] -ne $NUM ]; then
	echo "param wrong. Should be [number of project] [[project name] [project svn path] ...]"
	exit 1
fi

for (( i=1; i<=$N; i++ )); do
	j=$[$i * 2]
	p1=$j
	p2=$[$j + 1]
	create_project ${param[$p1]} ${param[$p2]}
	echo ${param[$p1]} " done !!!"
done
