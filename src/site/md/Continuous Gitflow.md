#### Continuous Gitflow

 Gitflow process leveraging Continuous Integration, Continuous Delivery and Continuous Test instrumentation. In a nutshell, the Gitflow model entails the creation and management of 5 core types of branches within a Git repository. These are:

  - Master: The primary branch-of-record for deployed code. Code at the HEAD of the master branch should be a snapshot of what is currently in production. If the gitflow model is properly implemented and maintained, this code should be already tested and deploy-ready. Each successive merge to Master represents a production release.
  - Develop: This is the primary branch-of-record for developing code. Develop represents the current state of developed code, and HEAD should contain all features ready for demonstration to the client stakeholders and/or product owners.
  - Feature(s): Feature branches are created by checking out the HEAD of develop. A Feature branch is a workspace for the collaborative/iterative development of a feature. This is often a unit of work achieved over many days by a particular developer, however it is not uncommon for multiple developers to work on a feature in parallel. Multiple features may be under development at a particular time, resulting in multiple feature branches. Work is typically merged back into develop as a feature reaches completion. In the Continuous Gitflow model, all merges into develop must be accomplished via a ‘Pull Request’ (or ‘PR’). The PR Review process will be discussed at length here and throughout this document.
  - Release: Release branches stand between Develop and Master. Even in the case of a mature CI/CD pipeline, consumer store deployment of mobile apps (for example) is a complex and lengthy process that constitutes a significant investment of time and money. Continuing from the mobile perspective, contemporary mobile applications often encapsulate sophisticated, deeply interrelated flows that may take the user through many sequences of rich screens. Given these factors, in order to achieve a seamless app store deployment, it is typically necessary to stabilize and regress a deployment version. This is done by creating a new release branch from the Develop branch, and iterating through successive stabilizing commits. Once a release branch is deemed production ready, it is deployed and merged to Master.
  - Hotfix: We largely leave this branch undiscussed, as deployment of critical patches and fixes is largely determined by business, product and technology context. However, in the original Driessen model, Hotfix branches are drawn from Master, critical fixes are iterated and tested, and then the code is merged back to both Develop and Master once deployed.

#### CI/CD/CT/CQ

Using the existing gitflow model, we achieve ‘continuous gitflow’ by instrumenting CI, CD and CT actions triggered by branch commits.

Defines regular processes and expectations around source management that reinforce quality concerns.

##### Feature(s):

  The CI/CD/CT pipeline for Feature branches should be set up to execute upon every check-in. This pipeline compiles the code, runs Static analysis tools, runs Unit Tests (for CT) and passes only if ALL steps were successful. Errors at any stage will be captured in the pipeline logs with specific information on why and where the failure occurred. A PR can be submitted to merge a Feature branch to Develop only if the pipeline builds successfully, thus installing an automated quality check at the feature level.

##### Develop:
  The CI/CD/CT pipeline for the Develop branch works similar to the Feature branch pipeline. Any code check-in or PR merged to the Develop branch will trigger a build including execution of Unit Tests (CT) and Static Analysis tools. Additionally, upon successful build, the pipeline should be configured to deploy the application to an internal staging repository and notify all the stakeholders (i.e. Scrum team, Product Owner, Client QA team, etc.). It is recommended that the Develop pipelines may be scheduled to run automated inetgration test (UI, security,...) at regular intervals (e.g., nightly) to capture any issues after PR merges, enhancing CT quality checks.

##### Release:

  Release branch pipelines run on Beta versions of the code. These should include stringent code inspection configuration rules to highlight any warnings that may have sneaked past the Develop pipelines. The Release branch pipeline must include execution of Unit Tests, Static analysis tools and automated regression testing. This pipeline must focus on continuous regression and should be executed on as many device configurations as possible. A regular scheduled execution of this pipeline is strongly recommended.

##### Master:

  Master branch pipelines run on code that has already been submitted to staging repository and hence the goal of these is to pre-emptively capture any issues in Production code. These pipelines should include all stages and must be executed at regular intervals. In the mobile context, this becomes especially salient when there are updates to the backend systems or updates to the APIs consumed by the app versions already available on App Stores.
