awk '!seen[$0]++' ~/.bash_history > ~/.bash_history_temp && mv ~/.bash_history_temp ~/.bash_history
