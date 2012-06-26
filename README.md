TO DO
v	fix vimeo display
v	add captions/credits/titles/descriptions to media items 
-	disable comments
v	better ckeditor button selection
v	add editor role
-	add administrator shortcuts
v	add editor shortcuts
x	look at media gallery modules
-	add user 1 to editors
- Less CSS
- Panels
- Responsive base themes


Things we have to do post install
-	Disable comments ( as we can't run standard_install without it )
-	Enable monograph_permissions ( as running that during install causes a critical error )

##To fork this repo (outside of Github)##

1. Clone the Monograph repo
`$ git clone git@github.com:queenvictoria/monograph.git demo-site
$ cd demo-site`
1. Check the remotes
`$ git remote -v`
`origin  git://github.com/queenvictoria/monograph.git (fetch)
origin	git://github.com/queenvictoria/monograph.git (push)`
1. Rename the origin
`$ git remote rename origin upstream`
1. Create a new repo at Github
1. Add origins for the new repo
`$ git remote add origin git@github.com:Laudanum/sturt.git`
1. Check the new origins
`$ git remote -v`
`origin  git@github.com:Laudanum/sturt.git (fetch)
origin	git@github.com:Laudanum/sturt.git (push)
upstream	git://github.com/queenvictoria/monograph.git (fetch)
upstream	git://github.com/queenvictoria/monograph.git (push)
`
1. Push up the new fork
`$ git push origin master`

I had to make a couple of manual changes to .git/config
1. Update [branch master]
`[branch "master"]
	remote = origin
	merge = refs/heads/master`
1. Correct the syntax for the monograph remove
`upstream	git@github.com:queenvictoria/monograph.git (fetch)
upstream	git@github.com:queenvictoria/monograph.git (push)`

##Update upstream from a fork##

`$ git fetch origin -v; git fetch upstream -v; git merge upstream/master`

##Push updates to upstream##

`$ git push upstream`