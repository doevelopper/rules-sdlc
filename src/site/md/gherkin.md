# Gherkin Style Guide

## Introduction
This file contains information and examples of how to style a gherkin document

## Table of Contents
1. [Overview](#overview)
1. [Keywords](#keywords)
   1. [Feature](#feature)
   1. [Descriptions](#descriptions)
   1. [Scenario](#scenario)
   1. [Steps](#steps)
      1. [Given](#given)
      1. [When](#when)
      1. [Then](#then)
      1. [And, But](#and-but)
   1. [Background](#background)
   1. [Scenario Outline](#scenario-outline)
   1. [Examples](#examples)
      1. [Data Tables](#data-tables)
   1. [Doc Strings](#doc-strings)
   1. [Comments](#comments)
   1. [Tags](#tags)
1. [Writing Gherkin Well](#writing-gherkin-well)
   1. [Formatting](#formatting) 
      1. [Indentation](#indentation)
      1. [Line length](#line-length)
   1. [Writing Tips](#writing-tips)
      1. [Phrasing](#phrasing)
      1. [Titles](#titles)
      1. [Imperative vs Declarative Steps](#imperative-vs-declarative-steps)
1. [See Also](#see-also) 

## Overview 

Gherkin is a simple programming language designed for writing behavior scenarios.
The "code" for Gherkin is written into text files with a .feature extension. 
This is known as a feature file.

## Keywords

Every statement in a feature file starts with a Gherkin keyword. Any text can 
follow a keyword (with a few exceptions).

The following is a high-level overview of Gherkin keywords.

<details open>
<summary>Gherkin Keyword Table</summary>
<table rules="all" border="1" summary="Guidelines from Guido's Recommendations"
       cellspacing="2" cellpadding="2">

  <tr>
    <th>Keyword</th>
    <th>Use</th>
  </tr>

  <tr>
    <td>Feature</td>
    <td>Describes the product or feature under test. Only one Feature per feature file</td>
  </tr>

  <tr>
    <td>Scenario</td>
    <td>Describes a specific behavior case. Features can contain multiple scenarios. 
    Each scenario is independent.</td>
  </tr>

  <tr>
    <td>Given</td>
    <td>Step that defines the initial state.</td>
  </tr>

  <tr>
    <td>When</td>
    <td>Step that defines an action to perform.</td>
  </tr>

  <tr>
    <td>Then</td>
    <td>Step that defines the expected result from the action.</td>
  </tr>

  <tr>
    <td>And</td>
    <td>Additional step added to a Given, When, or Then step. Grouped with 
    the preceding step.</td>
  </tr>

  <tr>
    <td>But</td>
    <td>Functions the same as the And keyword.</td>
  </tr>

  <tr>
    <td>Background</td>
    <td>Adds additional context to scenarios in a feature. Can contain one or more Givens.
    Ran for every scenario in a feature file.</td>
  </tr>

  <tr>
    <td>Scenario Outline</td>
    <td>uses '<' and '>' to identify parameter names for a templated scenario.
    Followed by Examples that provide the parameter values.</td>
  </tr>

  <tr>
    <td>Data Tables</td>
    <td>Uses '|' to construct a table for Examples and step tables</td>
  </tr>
  
  <tr>
    <td>Doc Strings</td>
    <td>Uses """ to pass large text into a step</td>
  </tr>

  <tr>
    <td>Comments</td>
    <td>uses '#' to denote a comment line</td>
  </tr>
  
  <tr>
    <td>Tags</td>
    <td>Uses '@' as a prefix to denote a tag. Tags can be placed prior to a Feature
    or Scenario</td>
  </tr>
  
</table>
</details>

### Feature
The purpose of the keyword is to provide a high-level overview of a feature
and group related scenarios.

The first primary keyword in a Gherkin document must be `Feature`, and is followed
directly by a `:` with a brief single line description of the feature.

Text can be added below the `Feature` keyword to provide more description.
Free text stops once another primary keyword such as `Scenario` is encountered.

```gherkin
Feature: Sample Feature
  This is a sample feature.
  The description can have multiple lines in it,
  but cannot start with a gherkin keyword.

  Scenario: Simple scenario
```

### Descriptions
Free-form text descriptions can also be placed under `Scenario` and 
`Scenario Outline`.

Anything can be placed in the description if no lines start with a keyword

### Scenario
A `Scenario` is a set of steps that represents a specific behavior case.
The most basic scenario contains three steps. Steps must be in the order 
`Given`-`When`-`Then`.

`Scenario` also requires `:` to be included right after the keyword.
A one-line description is placed after the keyword

```gherkin
Feature: Sample Feature
  This is a sample feature.
  The description can have multiple lines in it,
  but cannot start with a gherkin keyword.


  Scenario: Simple scenario
    Given some initial state
    When something happens
    Then check for the expected result
```

Scenarios can have any number of steps, but scenarios should be limited to 3-10
steps.

### Steps

Every step can start with any of the following keywords `Given`, `When`, `Then`, 
`And`, or `But`.

Steps are executed in the order they are written. When a step is executed, keywords
are not looked at for context of the text. The two steps below would be reduced 
to the same step definition.

```gherkin
When something happens
Then something happens
```

This means that steps should not be ambiguous and should be written in a clear 
language.

#### Given
The `Given` step is used to indicate the initial state of the system.
Givens are meant to put the system into a known state before a user interacts 
with the system.

Examples:
```gherkin
Given Bill and Ted have started an adventure
```

```gherkin
Given the user is logged in as default
```

#### When
The `When` step is used to indicate an action or event on the system.

Examples:
```gherkin
When the player presses the A button
```

```gherkin
When the user withdraws cash
```

#### Then

The `Then` step is used to indicate a result.

This step is where assertions should occur. It should compare the actual outcome
with the expected outcome.

Examples:
```gherkin
Then Mario double jumps
```

```gherkin
Then pictures should be installed on the user's laptop
```

#### And, But
`And` or `But` can be used to replace multiple `Given`, `When`, or `Then` steps.

Example:
```gherkin
# This is fine
Scenario: multiple steps
  Given something
  Given something else
  When this thing happens
  Then a cool thing happens
  Then another cool thing happens
  
# Same scenario, but This is better
Scenario: multiple steps
  Given something
  And something else
  When this thing happens
  Then a cool thing happens
  But another cool thing happens
```

### Background
If the same `Given` steps are being used across scenarios, then they can be grouped
into a background. The background can have one or more given statements.

Only one `Background` can exist per feature. The background is ran before each scenario.
If a scenario does not fit the background, then that scenario should be moved to
a different feature file. 

In the feature file, the `Background` steps should be placed prior to the scenarios.

```gherkin
Feature: using background

  Background: start at landing page
    Given the user is at the landing page
    
  Scenario: create user
    Given the user does not have a login
    When the user signs up
    Then the user account is created
    
  Scenario: login
    Given the user has a login
    When the user signs into their account
    Then the user is redirected to their dashboard 
```

### Scenario Outline
The `Scenario Outline` keyword is used to run the same scenario multiple times
with different data.

Example:
```gherkin
Scenario Outline: share cookies
  Given there are "<initial>" cookies
  When I share "<number>" cookies
  Then I should have "<left>" cookies
  
  Examples:
    | initial | number | left |
    |       5 |      2 |    3 |
    |      10 |      5 |    5 |
```

The Scenario Outline is run once for each row in the examples table.

#### Data Tables
`Data Tables` can be used to pass a list of values to a step.

```gherkin
Given the account exists
  |  name |           email |
  | Steve | steve@gmail.com |
  |  Bill |  bill@gmail.com |
```

Data tables will be passed into the step definition, where they can be 
manipulated.

### Doc Strings
`Doc Strings` can be used to pass a large body of text to a step definition.

The text in doc strings need to use three double-quote marks on their own line
to indicate the start and end of the doc string.

```gherkin
Given a GitLab README with markdown content
  """
  # Gherkin Style Guide
  
  ## Introduction
  """
```

### Comments
Like any other programming language, comments are allowed in the Gherkin language.

Comments are made by using the `#` symbol at the start of a line. Comments cannot
be in line with other keywords or steps.

```gherkin
Feature: some cool feature

# this is a comment
Scenario: some scenario
```

### Tags
Tags are used to indicate something within a feature file.
Tags begin with a `@` symbol and can be placed prior to a feature or scenario.

Example:
```gherkin
@test
Scenario: some scenario
  Given something
  When something happens
  Then something else happens
```

## Writing Gherkin Well

Gherkin is a simple language with a limited number of keywords. Anyone can write
a gherkin statement, but it can often be difficult to write one well.

This section goes through some formatting rules and tips for writing gherkin.

### Formatting

Because Gherkin is simple, there are only a few formatting conventions to follow.

#### Indentation

Indentation should increase by 2 spaces when a statement is contained underneath
another statement.

```gherkin
# good indentation
Feature: card game
  card game is designed for 2 players.
  One person draws a card, and the other player
  guesses the card.
  
  Scenario: guess card
    Given a game has started
    When the card is drawn
    Then the player guesses a card
```

```gherkin
# bad indentation
Feature: card game
card game is designed for 2 players.
    One person draws a card, and the other player
 guesses the card.
  
Scenario: guess card
Given a game has started
    When the card is drawn
Then the player guesses a card
```
#### Line length
Line length should be around 80-100 characters.

### Writing Tips

#### Phrasing

* Write all steps in third person
* Write complete sentences
* Given's use present or present-perfect tense
* When's and Then's always use present tense

Here are some examples illustrating poor phrasing.

```gherkin
# bad phrasing
Feature: store cart

   Scenario: empty cart
      Given I am putting items in the cart
      When the shopper removed all the items
      Then the cart will be empty
```

The above example has several bad phrases.
Not all steps are not written in third person. Having a mix of third and first person
can be confusing. It's better to always use third person.

For the Given step, 'I am putting' indicates an action is taking place. Given steps
should avoid actions. They are about the initial state and not about exercising some
behavior.

The When step is using past tense when it says, 'the shopper removed'. A When step
should be thought of as currently happening.

The step is using future tense when it says, 'the cart will be empty'. The problem
with using future tense in Then steps, is that it reinforces a procedure driven
test approach. A behavior is about the current condition of the system.

Below is the fixed example:
```
# good phrasing
Feature: store cart

   Scenario: empty cart
      Given a cart has items
      When the shopper removes all the items
      Then the cart is empty
```

#### Titles

Titles are important they should be descriptive and provide information.
Think about what you would want to read if you were being handed a document
for the first time.

#### Imperative vs Declarative Steps

Write declarative steps over imperative steps.

Imperative steps are very procedure driven and describe how something should happen.
Declarative steps say what should happen without spelling out how to get there.

Imperative steps might look like the below:

1. When the user clicks on the search bar
2. and the user types 'dogs'
3. and the user hits the enter key

Here is a declarative version:

1. When the user searches for dogs in the search bar

## See Also

1. [Gherkin Reference](https://docs.cucumber.io/gherkin/reference/)
1. [Gherkin Language](https://automationpanda.com/2017/01/26/bdd-101-the-gherkin-language/)
2. [Gherkin By Example](https://automationpanda.com/2017/01/27/bdd-101-gherkin-by-example/)
3. [Writing Good Gherkin](https://automationpanda.com/2017/01/30/bdd-101-writing-good-gherkin/)









