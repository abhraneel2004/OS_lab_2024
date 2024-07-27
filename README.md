

## Operating System Laboratory

Welcome to the Operating System Laboratory repository! This repository contains implementations of various operating system concepts and scripts in Bash. Whether you're a beginner looking to learn or an experienced developer seeking reference implementations, you've come to the right place.


## Cheat Sheet 😉

<a target="_blank" href="https://quickref.me/bash">Cheat Sheet</a>

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/6725a58a-baaa-467d-9069-35aab3f3bef6" style="width: 3%;"> Using Replit</h2> </span>
</div>


# Step-by-Step Guide: How to Use Bash in Replit.com

Replit.com is a powerful online IDE that allows you to write, run, and share code directly in your browser. Follow these steps to use Bash in Replit.

## Step 1: Create a New Repl

1. **Visit Replit:** Open your web browser and go to [Replit.com](https://replit.com).
2. **Log In/Sign Up:** If you don't have an account, sign up for one. If you do, log in.
3. **Start a New Repl:** Click the `+ Create` button on the top left of the dashboard.

## Step 2: Select the Bash Template

1. **Choose Template:** In the "Create a new Repl" window, type "Bash" in the search bar.
2. **Select Bash:** Click on the "Bash" template.

## Step 3: Set Up Your Project

1. **Name Your Repl:** Enter a name for your project in the "Title" field.
2. **Create Repl:** Click the `Create Repl` button.

## Step 4: Write Your Bash Script

1. **Open the Shell:** In the Replit IDE, you will see a file named `main.sh` opened by default.
2. **Edit the Script:** Write your Bash script in the `main.sh` file. For example, you can start with a simple script:
    ```bash
    echo "Hello, World!"
    ```
3. **Save Your Work:** Replit automatically saves your changes, but you can manually save them by clicking `Ctrl + S` or using the save button.

## Step 5: Run Your Bash Script

1. **Run the Script:** Click the `Run` button at the top of the screen. This will execute your `main.sh` script.
2. **View Output:** The output of your script will be displayed in the console at the bottom of the screen.

## Step 6: Install Additional Packages (if needed)

If your Bash script requires additional tools or packages, you can install them using the terminal:

1. **Open the Terminal:** Click on the `Shell` tab at the bottom of the Replit interface.
2. **Install Packages:** Use package manager commands to install the necessary packages. For example, to install `bc`:
    ```bash
    sudo apt-get update
    sudo apt-get install bc
    ```

## Step 7: Explore and Share

1. **Explore:** Feel free to explore more features of Replit, such as version control, collaborative coding, and more.
2. **Share Your Repl:** You can share your project by clicking the `Share` button and copying the link to share with others.

## Example Script

Here's an example of a simple Bash script that calculates the factorial of a number:

```bash
#!/bin/bash

factorial() {
  n=$1
  facto=1
  for ((i=1; i<=n; i++)); do
    facto=$((facto * i))
  done
  echo $facto
}

echo "Enter a number:"
read number
result=$(factorial $number)
echo "The factorial of $number is $result"
```

## Running the Example Script

1. **Copy the Script:** Copy the above script into your `main.sh` file.
2. **Run the Script:** Click the `Run` button to execute the script.
3. **Input a Number:** When prompted, enter a number to see its factorial.

---

By following these steps, you can easily write and execute Bash scripts using Replit.com. Happy coding!


<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/6725a58a-baaa-467d-9069-35aab3f3bef6" style="width: 3%;"> Installation and Setup in Loacal Machine</h2> </span>
</div>


### 1. Install `bc` and Bash

Make sure you have `bc` and Bash installed. You can install them using the following commands:

```bash
# Update package list
sudo apt-get update

# Install bc and bash
sudo apt-get install bc bash
```

### 2. VS Code (Optional)

Download and install [Visual Studio Code](https://code.visualstudio.com/). This repository is configured with a `.vscode` folder containing useful settings for your coding environment.

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/1c115655-468b-442b-a379-a571ded16107" style="width: 3%;"> Running the Code</h2> </span>
</div>

Navigate to the specific directory of the code you want to run and use the following commands:

```bash
# Make the script executable
chmod +x script_name.sh

# Run the Bash script
./script_name.sh
```

Replace `script_name.sh` with the name of your Bash script.

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/7c437a5b-2f8e-426a-bf5a-290ad2c3d99a" style="width: 3%;"> Contributing</h2> </span>
</div>

We welcome contributions from the community! To contribute to this project, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix: `git checkout -b feature-name`.
3. Make your changes and commit them with a descriptive commit message.
4. Push your changes to your fork: `git push origin feature-name`.
5. Open a pull request to the main repository.

Below is an explanation of the commands for forking and contributing to a GitHub repository:

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/ec813301-09b4-4c04-9730-b84df7f2fbd3" style="width: 3%;"> Forking the Repository</h2> </span>
</div>

1. **Fork the repository:** Click the "Fork" button at the top right of the repository page. This creates a copy of the repository in your GitHub account.

   ![Forking](gifs/fork.gif)

2. **Clone your forked repository:** Open your terminal and run the following command to clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/repository.git
   ```

   Replace `your-username` with your GitHub username and `repository` with the name of the repository.

   ![Clone](gifs/clone.gif)

## Contributing

1. **Create a new branch:** Move into the repository directory and create a new branch for your feature or bug fix:

   ```bash
   cd repository
   git checkout -b feature-name
   ```

   Replace `feature-name` with a descriptive name for your contribution.

   ![Branch](gifs/branch.gif)

2. **Make your changes:** Modify the code, add new features, or fix bugs. Once done, stage and commit your changes:

   ```bash
   git add .
   git commit -m "Description of changes"
   ```

   Replace "Description of changes" with a concise and descriptive commit message.

   ![Commit](gifs/commit.gif)

3. **Push to your fork:** Push your changes to your forked repository on GitHub:

   ```bash
   git push origin feature-name
   ```

   Replace `feature-name` with the name of your branch.

   ![Push](gifs/push.gif)

4. **Create a Pull Request (PR):** Go to the GitHub page of your forked repository. GitHub will detect the recent push and display a "Compare & pull request" button. Click on it to create a new pull request.

   ![Pull Request](gifs/pull_request.gif)

   Add a title and description to your pull request, then click "Create Pull Request."

   ![Create Pull Request](gifs/create_pr.gif)

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/c65c4a88-e884-45ab-916c-2fe481de6c23" style="width: 3%;"> Points to remember:</h2> </span>
</div>
   
- Add only code files

![Open Source GIF](gifs/open_source.gif)

<div>
<h2><span> <img src="https://github.com/abhraneel2004/MAKAUT_3rdSem_DSA_AOT/assets/115551450/a8da64a4-fbc7-44ec-97ce-ef38135d0b1a" style="width: 4%;"> Acknowledgements</h2> </span>
</div>

We appreciate the open-source community and contributors for making this project better every day. Special thanks to [GitHub](https://github.com/) for providing an excellent platform for collaboration.

---

**Note:** Replace `script_name.sh` with the appropriate names for your script file and desired output executable.

<div align="center">
<img src="https://media.giphy.com/media/L1R1tvI9svkIWwpVYr/giphy.gif" alt="Coding GIF" style="width: 50vw; overflow:hidden;">
</div>
