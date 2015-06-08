#!/bin/bash
git filter-branch --commit-filter '
        if [ "$GIT_AUTHOR_EMAIL" = "bdepwgjqet@gmail.com" ];
        then
                GIT_AUTHOR_NAME="白隼";
                GIT_AUTHOR_EMAIL="yonghong.yyh@alibaba-inc.com";
                git commit-tree "$@";
        else
                git commit-tree "$@";
        fi' HEAD
