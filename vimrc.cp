source ~/.vim/plugins.vim
syntax on

set relativenumber
set number
set pastetoggle=<F3>
set spell spelllang=en_us
set showmatch
set cursorline
set tabstop=4             " Tab size of 4 spaces
set softtabstop=4         " On insert use 4 spaces for tab
set shiftwidth=4
set expandtab             " Use apropiate number of spaces
set noswapfile            " Do not leve any backup files
let &t_SI = "\e[6 q"      " Make cursor a line in insert
let &t_EI = "\e[2 q"      " Make cursor a line in insert
let python_highlight_all = 1
set path+=** "Provides tab-completion for all file-related tasks
set wildmenu " Display all matching files when we tab complete
set noshowmode
set bg=dark
set laststatus=2

let g:gruvbox_italic=1
let g:lightline = {
      \ 'colorscheme': 'jellybeans',
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ],
      \             [ 'gitbranch', 'readonly', 'filename', 'modified' ],
      \             [ 'linter_checking', 'linter_errors', 'linter_warnings', 'linter_infos', 'linter_ok' ]]
      \ },
      \ 'component_expand': {
      \   'linter_checking': 'lightline#ale#checking',
      \   'linter_infos': 'lightline#ale#infos',
      \   'linter_warnings': 'lightline#ale#warnings',
      \   'linter_errors': 'lightline#ale#errors',
      \   'linter_ok': 'lightline#ale#ok',
      \  },
      \ 'component_type': {
      \   'linter_checking': 'right',
      \   'linter_infos': 'right',
      \   'linter_warnings': 'warning',
      \   'linter_errors': 'error',
      \   'linter_ok': 'right',
      \ },
      \ 'component_function': {
      \   'gitbranch': 'FugitiveHead'
      \ },
      \ }
let g:python3_host_prog='/usr/bin/python3'
let g:ale_python_executable='python3'
let g:ale_fixers = {
            \   'python': ['autopep8', 'yapf'],
			\   'javascript': ['prettier'],
			\   'css': ['prettier'],
			\   'scss': ['prettier'],
			\   'html': ['prettier'],
			\}
let g:ale_linters = {
			\   'python': ['black', 'pylint'],
			\   'javascript': ['eslint'],
			\   'vue': ['eslint']
			\}
let g:ale_fix_on_save = 1
let g:closetag_regions = {
    \ 'typescript.tsx': 'jsxRegion,tsxRegion',
    \ 'javascript.jsx': 'jsxRegion',
    \ 'typescriptreact': 'jsxRegion,tsxRegion',
    \ 'javascriptreact': 'jsxRegion',
    \}
let NERDTreeQuitOnOpen=1



autocmd vimenter * ++nested colorscheme gruvbox
" automatically rebalance windows on vim resize
autocmd VimResized * :wincmd =
" zoom a vim pane, <C-w>= to re-balance
nnoremap <leader>- :wincmd _<cr>:wincmd \|<cr>
nnoremap <leader>= :wincmd =<cr>
" use ctrl space for esc
nnoremap <C-@> i
inoremap <C-@> <Esc>
