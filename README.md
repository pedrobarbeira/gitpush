# GITPUSH

### WHAT IT IS ###
Gitpush is a simple dev tool that aims to simplify and fast track the usage of
git through the command line. How many times have you finished that 4-hour long
debug session only to push your changes and realize you forgot to delete comments,
or remove TODO/FIXME tags, or integrate the fix, and had to add, commit and push
all of it again? How many times have you done this only to realize you forgot
some other minor change and had to do it yet again? This short example describes
what gitpush aims to solve by compressing these frequently used command sequences
into a short, simple sintax. Instead of git add . + git commit -m "message" + git
push remote branch, you type gitpush "message" in your console and the script
handles it for you. Simple and easy.



### HOW IT STARTED ###
A couple weeks ago I formated the wrong usb thumb drive after migrating my whole
system from Windows to Linux. All my documents were lost. All my code was lost.
Fortunately most of the stuff that mattered was already stored in cloud space.
This got me thinking, so I decided to upload all my code to git from now on. The
whole codebase. This lead to trying to push a repository which had repositories
inside it, which introduced me to git submodules - a great feature of git, 
specially for large projects, which neither I nor anyone I've asked about
knows of. Unfortunately, pushing a repository with submodules adds up to
very verbose code. Something like "git push --recurse-submodules=on-demand
origin master". A very long line to type every time a push was required.
This gave birth to the idea of making a shellscript that did it for me. But
a shellscript is pretty limited, so I decided to write the script in C. One
thing led to another, ideas started popping up, and the realization that I
stumbled upon a very interesting project came through.



### WHY PURSUE IT ###
We all use git, and none of us has ever read the manual. If we want something
specific done we run a google search and check out what comes up in stack overflow.
Git as a tool has several years of development on it's shoulders. There certainly
are more interesting features like git submodules that can make our life much
easier and our coding experience much richer. The kind of stuff we don't even
know we need - at least that was what submodules were for me. Through this project
we get a chance to dive deeper then the usual add-commit-push cycle, and applying
that knowledge to make a tool that facilitates using git both for ourselves and
everyone that bumps into it. Ideas tend to present themselves once we start 
getting our hands busy, so picking up something simple is always a good place 
to start. It's less about what it is and more about how much you can make it
grow.



### WHERE IT'LL GO ###
Gitpush is at a very early stage of it's development. It's basically a fetus.
Maybe even an embryo. Right now all it does it adding all your files, commiting
them - defaults to system date if no user message (80char max) is specified -
and pushing them to origin master. All this means is that the seed has been 
planted and now it's time to water and nurter it. You can find the planned
future features bellow:



@FUTURE FEATURES:
- Cross-platform support
- gitpush -a <filename>... :: only commits files specified in the argument list
- gitpush -c <url> :: automatically initializes a repository and sets it's
  remote url to url. 
- gitpush -b <branch> <optional_message> :: pushes to branch <branch> with either
  an user-defined message or the system date(default)
  gitpush -l <message> :: allows for messages above 80 characters
  
 Again, simplicity is key. Gitpush will aim for different degrees of exposition 
 of the git API. The point is figuring out the most common usages of Git and
 automating them for a more fluid utilization. Each of these commands can be
 easily extended - for example, the gitpush -c command can be extended to allow
 user to name his remote and master/main branch however he desires, the whole 
 tool can be extended to handle multiple remotes in the same repository at
 once, etc. 

  
  
### HOW TO CONTRIBUTE ###
If the project speaks to you in any way, feel free to contact me either through
git or through pedro.barbeira95@gmail.com - be sure to use [GITPUSH] at the 
start of the subject.

### LICENSES ###
Gitpush uses the GPL3.0 license. 

@Contributors:
- pedrobarbeira
