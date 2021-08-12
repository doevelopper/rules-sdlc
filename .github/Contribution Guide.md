# Contribution Guide

We welcome all contributions to this repository especially in relation to open issues. However we request that you follow this guide when opening Pull Requests.

## Submission Guidelines

The following guidelines will ensure that the correct workflow is followed when submitting pull requests for this repository.

### 1\. Create an appropriate branch from Master

The first stage is to create a branch based on the up to date master branch. The naming convention should be the name of your changes prefixed by one of four choices.

Choice      | Description                                                                                                               | Example
----------- | ------------------------------------------------------------------------------------------------------------------------- | -----------------------------------------
hotfix      | An important fix to a bug that needs to be merged as soon as possible                                                     | hotfix-dates-displaying-incorrectly
bugfix      | A bug that has been discovered that is not of major importance and can be merged with the next minor update               | bugfix-item-is-missing
enhancement | An enhancement to an already implemented feature, or a small change that will be implemented with a small ammount of code | enhancement-navbar-height-changed
feature     | A large feature that will be worked on over a number of days / weeks which usually has a completion date attached to it   | feature-automatic-creation-of-client-pack

### 2\. Create documentation and create pull request

`Not applicable for hotfix and bugfix submissions`

If you will be creating a pull request for a feature or an enhancement then you should create documentation for the feature you are implementing. This should follow our normal documentation style for API related additions, for other general code a basic layout can be designed in comments.

Once the documentation for this stage is complete you must then submit a Pull Request. This will allow all developers working on the project to review you ideas and changes and comment accordingly with ideas and suggestions.

### 3\. Test, Test, Test

All pull requests **must** be accompanied by appropriate unit tests, this is the best point to create your unit tests so you follow a TDD structure. If you do not wish to follow a TDD structure then that is not a requirement, however, pull requests will never be merged without appropriate tests.

### 4\. Write your code

This is, as we all know, the fun bit. Write your code, create your feature, we can't wait to see it! Please just ensure that your code follows our [coding standards](#coding-standards).

### 5\. Merge in master

Once you are happy with your code and you are sure that it is complete we suggest that you pull any changes into your local master branch and then merge your master branch with your new feature branch. This will ensure that there are no conflicts and also allows you to run your tests with all the latest code.

### 6\. Alert code review

Push your final changes to your branch and then alert the code review team that you are happy for your work to be merged. To do this simply add an appropriate comment to your pull request and tag @code-review. Something like the following will suffice.

`@code-review : All changes complete, this branch is ready to merge in once code review is complete.`

## Coding Standards

Laravel follows the [PSR-4](https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-4-autoloader.md) and [PSR-1](https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-1-basic-coding-standard.md) coding standards. In addition to these standards, the following coding standards should be followed:

- The class namespace declaration must be on the same line as <?php.
- A class' opening { must be on the same line as the class name.
- Functions and control structures must use [Allman style](https://en.wikipedia.org/wiki/Indent_style#Allman_style) braces.
- Indent with tabs, align with spaces.
