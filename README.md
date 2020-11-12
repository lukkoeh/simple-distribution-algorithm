# Simple distribution algorithm
An algorithm, which allows to distribute values almost equal to multiple objects.

## How does it work?

This algorithm takes a set of numbers which are supposed to be distributed around a amount of recipients. It uses some quite simple methods to find the most equal distribution for the amount of recipients given. The process is divided into X steps:

### Step 1: Prepare the dataset
The first step is to fill up the container of data which was given by the user or other institution. The size of the container has to be a multiple of the amount of recipients given. This is made possible by adding zeros to our container until the targeted size is reached (size_of_container % amount_of_recipients == 0). After that, the dataset is ordered in descending order as a preparation for the next step.

#### Example
Numbers: { 1,2,3,4,5,6,7,8 }
Recipients: 3
&rarr; Numbers after adding zeros: { 1,2,3,4,5,6,7,8,0 }, because 9 % 3 = 0 (9 = size of our dataset).
&rarr; Numbers after ordering: { 8,7,6,5,4,3,2,1,0 }

### Step 2: Dividing the dataset into blocks
The dataset is now divided into multiple blocks. Each block's size equals the amount of recipients.

#### Example
Numbers: { 8,7,6 | 5,4,3 | 2,1,0 } (Blocksize = 3)

### Step 3: Ordering every second block in reverse order
Every second block is now ordered in ascending order.

#### Example
Numbers: { 8,7,6 | 3,4,5 | 0,1,2 }

### Step 4: Adding values together
From each block, the first, second, third and so on number is added together. As a result, we get as many numbers as recipients were given. Each number represents the value that recipient x receives.

#### Example
Numbers: 
{ 
  8,7,6
  3,4,5
  0,1,2
}

Results: 11; 12; 13;
If everything worked correctly, this is the best possible distribution (fairest).

## Usage

Make sure that you include the SDA.h header file into your project. After that you are able to instance a SDA object in C++ like so:
```SDA object_name;```

And call its "distribute" function like this:
```object_name.distribute(<data_object>, <amount of recipients>);```

After that you can use the function "distribute" to distribute any amount of integers to any amount of recipients. In this repository you may find a simple example of how one can use this function. It uses a std::vector<int> as input and output. Furthermore, the function can adjust the amount of people one wants to distribute to.