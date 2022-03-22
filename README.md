# Flappy-Block

Hi !!:wave: Welcome to our game project "Flappy Block":icecream:

We are **Liu Yitao** and **Zhang Yuxiang** :nerd_face:

Here are some introductions about our game:popcorn: Hope you can enjoy it! :beer:


## 1. Introduction

One day :cityscape: , a dog named  BAILEY :poodle: was caught in a factory:factory: and packed into a magical cardboard box:package: . It is pretty difficult for him to escape from the box, so he decides to use the magic of this box to run this strange factory.

**1. 1: Strange factory:**

* There are countless **moving walls** in this factory. They are called "obstacles". Fortunately, **each wall has a gap**, but the **position of the hole is random**. Over time, the factory automatically controls the wall to speed up. Players need to **control the jumping trajectory of the carton** to make the carton **through these gaps**. **Note that anything that touches any wall will be grabbed back to the starting point.**:beers:

* Here is a possible situation:

  Players should control the box by using the magic of the box to pass through the gaps in the walls from left to right.

  ———————————————>

  :no_entry: :white_check_mark: :no_entry: :white_check_mark: :white_check_mark: :white_check_mark: :no_entry:......

  :no_entry: :white_check_mark: :white_check_mark: :white_check_mark: :no_entry: :white_check_mark: :no_entry:......

  :package: :white_check_mark: :no_entry: :white_check_mark: :no_entry: :white_check_mark: :white_check_mark:......

  :no_entry: :white_check_mark: :no_entry: :white_check_mark: :no_entry: :white_check_mark: :no_entry:......             

  ———————————————>
	
	:no_entry: means the walls.
	
	:white_check_mark:: means the region that the box could stay.

**1. 2: Magic of the box:**

1. **Jump in the air**: Allow BAILEY to jump in the air. After air jump, the box will **raise by half a meter**.

2. **Clean !!**: **Clear all obstacles** in the next five seconds.

   **Note:** This magic box hasn't solved gravity yet so the package will **fall freely** under the force of gravity.

   

## 2. A list of features that we plan to implement

1. Randomly generate the locations of the wall's gaps. ( Requirement 1 covered )
2. Linearly increases walls movement speed.
3. Using the keyboard to control the jumping of the carton and the second magic.
4. Function that could achieve "Clean !!" magic.
5. Function that could caluate the path of the box.
6. Individual files to control the functions, including speed calculation, random number generation, archiving, etc.  ( Requirement 5 covered )
7. Game interface that supports starting new games and loading archives.
8. Archive function. Saving the status by saving some critical variables in a file. When loading the archive, the code will get the variables in the file as the input. ( Requirements 2, 4 covered )
