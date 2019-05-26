#!/bin/bash
#Program:
#	quick commit and push to github for all in update file.
#
#History:
#	2019/4/30	---SPeak
git pull origin master
git add .
git status
git commit -m "quick commit and push to github by script"
git push origin master
echo -e "\n-----commit and push complete.-----\n"
exit 0
