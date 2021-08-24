# Documentation Best Practices
"If we can hit that bull's-eye, the rest of the dominoes will fall like a house
of cards. Checkmate." - Zapp Brannigan 

## Update Documentation with Code
It's easy to forget what you were doing yesterday. Update documentation with any
code change. **Merge requests should contain documentation changes and code
changes**

Doing so will keep documentation up-to-date and make it easier for people to
understand what you were doing.

**Reviewers**: Don't let code slip in without requesting that all documentation
(docstrings, README.md files, ect) be updated in the same Merge request.

## Keep It Simple
Keep documents simple and to the point. Clean and accurate documents are better 
than some unmanageable Hydra. Keep updating documents, throw out anything unnecessary.
Documents are easier to manage when updates and revisions are done frequently 
and in small quantities.

## Bring Out Your Dead (Docs)!
Old dead documentation is bad. In some ways, incorrect documentation is worse 
than no documentation. It can mislead, and cause laziness in engineers.
Why would they update their documentation if there is outdated docs in the
rest of the codebase?

It's best to delete any abandoned documentation. Not all documentation needs to
removed right away. Start by removing things you know are dead. Leave any
questionable documentation for later. If your codebase is large, involve everyone
in reading the documentation. If you're moving a project, leave anything dead or
possibly dead behind.

## You Can't Always Get Whay You Want
Not every document will be perfect. A document should be as good as possible within
a reasonable timeframe. Each reviewer has different opinions, but that shouldn't
stop releases or code changes. Choose to accept a "good" document over a "perfect"
one. Over time, the quality of the document will improve as authors understand
what indormation is needed in the document.

## Coding Doesn't End With The Code
A project doesn't end with its code. Sure the code works, but will anybody 
understand it? You might be planing on a robot overlord, but for now write
for humans first, robots second. 

Documentation is a broad spectrum of content, from comments to detailed designs:  
1. **Inline Comments**: Its purpose is to provide information the code can't,
like why you wrote it in the first place
    
1. **Method and Class comments**:  
 * Method API Documentation: This comment, whether it's a docstring or header,
says what your method will do. Its ensuring that your code does what you say,
no more or less.  
The documentation should minimaly say what arguments are taken, what is 
returned, any special cases or restrictions, any exception it can throw
or error it can return.
 * Class/Module API Documentation: This documentation gives an overview
of what the class/file does, and often contains some examples of how to
use the class/file.
    
1. **README**: A README file lets users know what the purpose of a directory
is for and points to any pertinent reference material.
    
    

