# Contributing to CUB3D

Welcome! We're excited to have you (well, us!) contributing to this project.
To ensure a smooth and efficient collaboration, please take a moment to review these guidelines.

## Coding Style

We adhere to the **norm** coding style from 42 school.
Please ensure all contributions are compliant with these standards.
This helps maintain code consistency and readability.

## Branching Strategy

For this project, we'll use a simplified branching model where branches are
named using our initials (First Name initial followed by Last Name initial,
e.g., `dm`) followed by a slash and a descriptive name for the task.

- **`main`**: This branch represents the most stable and up-to-date version of
  our game.
  Direct pushes to `main` should be avoided.
  All work should be done in a personal task branch and then merged into `main`.

- **Personal Task Branches:**
  - When you start working on a new feature, bug fix, or any distinct piece of
    work, create a branch prefixed with your initials followed by a slash and a descriptive name for the task.
  - **Examples:**
    - If 'dm' is working on player movement: `dm/player-movement`
    - If 'js' is fixing a collision bug: `js/fix-collision-bug`
  - **Important:** Before creating a new branch, always make sure your local
    `main` branch is up-to-date with the remote repository:
    ```bash
    git checkout main
    git pull origin main
    git checkout -b YOUR-INITIALS/your-task-description 
    # e.g., git checkout -b dm/implement-textures
    ```

## Commit Conventions

We use **Conventional Commits** for our commit messages.
This creates an explicit commit history, making it easier to understand changes and track
project progress.

Each commit message consists of a **header**, a **body** (optional), and a **footer** (optional).
The header has a special format that includes a **type**, a **scope** (optional), and a **subject**:
`<type>(<scope>): <subject>`

### Common Commit Types:

- **`feat`**: A new feature (e.g., adding a new game mechanic, level element).
- **`fix`**: A bug fix (e.g., correcting raycasting logic, fixing a crash).
- **`chore`**: Routine tasks, maintenance, or project setup (e.g., updating
  assets, small config changes).
- **`docs`**: Documentation only changes (e.g., updating this `CONTRIBUTING.md`
  or comments in code).
- **`style`**: Changes that do not affect the meaning of the code (white-space,
  formatting, missing semi-colons, etc., to align with **norm**).
- **`refactor`**: A code change that neither fixes a bug nor adds a feature
  (e.g., improving the structure of raycasting functions).
- **`perf`**: A code change that improves performance (e.g., optimizing
  rendering loops).

### Examples:

- `feat: implement basic enemy AI`
- `fix(raycaster): correct wall texture mapping`
- `docs: add notes on map format`
- `chore: update Makefile for new assets`
- `refactor(player): simplify movement input handling`

## Contribution Workflow

1.  **Discuss:** Briefly sync up on what you plan to work on.
2.  **Update `main`:** Ensure your local `main` branch is up-to-date:
    ```bash
    git checkout main
    git pull origin main
    ```
3.  **Create Branch:** Create your task branch from `main`:
    ```bash
    git checkout -b YOUR-INITIALS/your-task-description 
    # e.g., git checkout -b dm/add-raycasting-logic
    ```
4.  **Code & Commit:** Make your changes. Commit your work using the Conventional Commits format.
    ```bash
    git add .
    git commit -m "feat: implement basic wall rendering via raycasting"
    ```
5.  **Push Branch:** Push your branch to the remote repository:
    ```bash
    git push origin YOUR-INITIALS/your-task-description
    ```
6.  **Create Pull Request (PR):** Open a Pull Request on GitHub/GitLab (or your platform of choice) from your branch to `main`.
7.  **Review & Merge:** Review each other's PR. Once approved, merge it into `main`. Delete the branch after merging.

## Communication

- Let's keep each other updated on our progress and any blockers, especially before starting major work, to avoid conflicts.
- Use slack for discussions.
- Use Pull Request comments for code-specific feedback.

Happy Coding\!
