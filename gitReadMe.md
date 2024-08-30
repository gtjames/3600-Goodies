The basic workflow of GitHub involves a series of steps to manage and collaborate on code repositories effectively. Here is a summary of the typical workflow along with the key Git commands involved:

1. **Setup and Configuration**

•	**Install Git**: Install Git on your local machine.

•	**Configure Git**: Set up your Git identity.

`git config --global user.name "Your Name"`
`git config --global user.email "your.email@example.com"`

2. **Creating a Repository**

•	**Initialize a Repository**: Create a new local repository.

`git init`

•	**Clone a Repository**: Clone an existing repository from GitHub.

`git clone https://github.com/gtjames/3600-Goodies.git`

3. **Making Changes**
•	**Stage Changes**: Add changes to the staging area.

`git add <file>`
`git add .  # To stage all changes`

•	**Commit Changes**: Save changes to the local repository.

`git commit -m "Commit message"`

4. **Synchronizing with GitHub**

•	**Push Changes**: Send changes to the remote repository on GitHub.

`git push origin main`

•	**Pull Changes**: Update local repository with changes from the remote repository.

`git pull origin main`

5. **Branching and Merging**

•	**Create a Branch**: Create a new branch for development.

`git checkout -b feature-branch`

•	**Switch Branches**: Switch to another branch.

`git checkout main`

•	**Merge Branches**: Merge a branch into the current branch.

`git merge feature-branch`

6. **Collaboration**

•	**Forking**: Create a personal copy of a repository on GitHub.

•	**Pull Requests**: Propose changes to be merged into the main repository.
- Create a pull request on GitHub by comparing branches and submitting it for review.

7. **Inspecting and Reviewing History**

•	**View Commit History**: Check the history of commits.

`git log`

•	**Show Changes**: View changes made in commits.

`git diff`

** Common Git Commands Overview**

| Command	| Description |
| --- | ------------ |
| `git init` | Initialize a new Git repository. |
| `git clone <repo>` | Clone an existing repository. |
| `git status`	| Show the working directory status. |
| `git add <file>`	| Add a file to the staging area. |
| `git commit -m "message"`	| Commit changes with a message. |
| `git push origin <branch>`	| Push changes to the remote repository. |
| `git pull origin <branch>`	| Pull changes from the remote repository. |
| `git checkout -b <branch>`	| Create and switch to a new branch. |
| `git merge <branch>`	| Merge a branch into the current branch. |
| `git log`	| View commit history. |
| `git diff`	| Show changes between commits or the working directory. |
| `git remote add origin <url>`	| Add a remote repository. |
| `git fetch origin`	| Fetch changes from the remote repository. |
| git branch | List, create, or delete branches. |
| `git rebase <branch>` | Reapply commits on top of another base tip. |

### Detailed Example Workflow

1.	**Create a New Repository on GitHub**
- Go to GitHub and create a new repository.

2.	**Clone the Repository Locally**

`git clone https://github.com/username/repo.git`

3.	**Make Changes Locally**
- Edit files as needed.

4.	**Stage and Commit Changes**

`git add .`

`git commit -m "Initial commit"`

5.	**Push Changes to GitHub**

`git push origin main`

6.	**Create a New Branch for a Feature**

`git checkout -b new-feature`

7.	**Develop the Feature**
- Make and commit changes on the new feature branch.

8.	**Merge the Feature Branch**

`git checkout main`

`git merge new-feature`

9.	**Push Merged Changes to GitHub**
`git push origin main`

### References
-	GitHub Docs
-	Atlassian Git Tutorials
-	Pro Git Book
