set-option -g default-shell /bin/zsh
run-shell ~/clone/path/resurrect.tmux
unbind C-b
set -g prefix C-s

bind-key r source-file ~/.tmux.conf \; display-message "~/.tmux.conf reloaded"

set -g default-terminal "screen-256color"
set -g status-bg '#666666'
set -g status-fg '#aaaaaa'
set -g status-left-length 50
set -g status-right " #(date '+%a, %b %d - %I:%M') "

bind c new-window -c "#{pane_current_path}"

set -g base-index 1
set -g renumber-windows on

# Smart pane switching with awareness of Vim splits.
# See: https://github.com/christoomey/vim-tmux-navigator
is_vim="ps -o state= -o comm= -t '#{pane_tty}' \
    | grep -iqE '^[^TXZ ]+ +(\\S+\\/)?g?(view|n?vim?x?)(diff)?$'"
bind-key -n 'C-h' if-shell "$is_vim" 'send-keys C-h'  'select-pane -L'
bind-key -n 'C-j' if-shell "$is_vim" 'send-keys C-j'  'select-pane -D'
bind-key -n 'C-k' if-shell "$is_vim" 'send-keys C-k'  'select-pane -U'
bind-key -n 'C-l' if-shell "$is_vim" 'send-keys C-l'  'select-pane -R'
tmux_version='$(tmux -V | sed -En "s/^tmux ([0-9]+(.[0-9]+)?).*/\1/p")'
if-shell -b '[ "$(echo "$tmux_version < 3.0" | bc)" = 1 ]' \
    "bind-key -n 'C-\\' if-shell \"$is_vim\" 'send-keys C-\\'  'select-pane -l'"
if-shell -b '[ "$(echo "$tmux_version >= 3.0" | bc)" = 1 ]' \
    "bind-key -n 'C-\\' if-shell \"$is_vim\" 'send-keys C-\\\\'  'select-pane -l'"

bind-key -T copy-mode-vi 'C-h' select-pane -L
bind-key -T copy-mode-vi 'C-j' select-pane -D
bind-key -T copy-mode-vi 'C-k' select-pane -U
bind-key -T copy-mode-vi 'C-l' select-pane -R

bind-key \\ split-window -h -c "#{pane_current_path}"
bind-key - split-window -v -c "#{pane_current_path}"

# breaks plane into window
bind-key b break-pane -d

# Fine adjustment (1 or 2 cursor cells per bump)
bind -n S-Left resize-pane -L 2
bind -n S-Right resize-pane -R 2
bind -n S-Down resize-pane -D 1
bind -n S-Up resize-pane -U 1

# Coarse adjustment (5 or 10 cursor cells per bump)
bind -n C-Left resize-pane -L 10
bind -n C-Right resize-pane -R 10
bind -n C-Down resize-pane -D 5
bind -n C-Up resize-pane -U 5

# choose session tree
bind-key C-j choose-tree

# Use vim keybindings in copy mode
setw -g mode-keys vi

# Setup 'v' to begin selection as in Vim
bind-key -T copy-mode-vi v send -X begin-selection
bind-key -T copy-mode-vi y send -X copy-pipe "xclip -selection clipboard" 

# Update default binding of `Enter` to also use copy-pipe
unbind -T copy-mode-vi Enter
bind-key -T copy-mode-vi Enter send -X copy-pipe "xclip -selection clipboard"

# kills current session and switch
bind-key K run-shell 'tmux switch-client -n \; kill-session -t "$(tmux display-message -p "#S")" || tmux kill-session'

# call htop in its own window
bind-key h split-window -h "htop"
