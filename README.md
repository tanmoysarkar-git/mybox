First time set github project

git init

git add -A

git commit -m 'Added my project'

git remote add upstream https://github.com/tanmoysarkar-git/mybox

git push -u -f upstream master

With this, there are a few things to note. The -f flag stands for force. This will automatically overwrite everything in the remote directory. We’re only using it here to overwrite the README that GitHub automatically initialized. If you skipped that, the -f flag isn’t really necessary.

The -u flag sets the remote origin as the default. This lets you later easily just do git push and git pull without having to specifying an origin since we always want GitHub in this case.

git clone https://github.com/tanmoysarkar-git/mybox

vscode will automatically authorize itself. 

git push -f -u