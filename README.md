# minishell
>As beautiful as a shell

</p>
<p align="center">
	<a href="#about">About</a> •
	<a href="#usage">Usage</a> •
	<a href="#norme">Norme</a>
</p>

## About
The Minishell project is the first group project in the Common Core of school 42 and consists of creating a shell program in C using bash as a reference. 


## Usage
#### 1st - Clone the repository
``` bash
$ git clone git@github.com:MartimPinto/philosophers.git
```
#### 2nd - Enter the project folder and run Make or Make bonus
``` bash
$ cd philosophers

$ make
```
#### 3rd - Run the Program
You can run the program writing numerical values in the following arguments. The last parameter is optional
```bash
$ ./philo [n of philos] [time to die] [time to eat] [time to sleep] [n times each philo must eat]
```
#### 4th - Test with the following examples

| Example | Expected Result |
| :-- | :-- |
| `./philo 5 800 200 200`           | No philosopher should die.                                     |
| `./philo 5 800 200 200 7`         | The program stops when each philosopher has eaten 7 times.     |
| `./philo 4 410 200 200`           | No philosopher dies.                                           |
| `./philo 4 310 200 200`           | A philosopher dies.                                            |

The program will accept any positive values below or equal to the maximum int value (2147483647)


## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function
