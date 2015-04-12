runtime bundle/vim-pathogen/autoload/pathogen.vim
call pathogen#infect()

"语法高亮
syntax on
syntax enable

"根据文件类型设置缩进
filetype plugin indent on

"行号
set nu

"自动缩进
set ai

"显示行号列号
set ruler

"C程序缩进
set ci
set nocp
set backspace=indent,eol,start

"基于ai的改进
set smartindent

"一个tab占4个空格
set tabstop=4

"每层缩进空格数=4
set shiftwidth=4

"每次退格将删除4个空格
set softtabstop=4

"将tab自动展开成空格
set expandtab

"vim 内部编码方式
set encoding=utf-8

"避免在非utf-8系统中出现乱码
set langmenu=zh_CN.UTF-8
language message zh_CN.UTF-8

"vim用于屏幕显示(例如Xshell编码)的编码
set termencoding=utf-8

"文件编码
set fileencoding=utf-8

"打开文件时vim会逐一尝试用fileencodings中的编码进行解码
set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1

set completeopt=longest,menu

" ctags
set tags=/home/bdep__/code/acmt/tags

" taglist
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1

" winManager
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

" cscope
set cscopequickfix=s-,c-,d-,i-,t-,e-
cs add /home/bdep__/code/acmt/cscope.out /home/bdep__/code/acmt
