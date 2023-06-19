# CS210-ProgrammingLanguages

//Summarize the project and what problem it was solving.

For the project I chose, Project 2, we were building a solution for a banking application that would model the projection of an account balance based on
an initial deposit, an optional monthly deposit, a chosen annual interest rate, and the number of years projected the account would mature. The solution
was to take the user's information and outupt a chart that displayed both the yearly balance with and without the monthly deposits.

//What did you do particularly well?

I believe that I progressed in my ability to compartmentalize my functions and structure my code so that it can be maintained better than I have in previous
work.  I did make some mistakes which I was able to learn from - for example my Class had cout built within it, something I had not considered to be an issue
prior to getting feedback on this project. With regard to that, though, I am fairly happy with my development of finding a solution for executing a task that
I had no knowledge of how to complete prior. While I acknowledge that it may be possible to find other code in the world that may solve my problem, being able
to search the documentation and find a solution to apply to the problem is a skill I believe I strengthened here.

//Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

Up to this point, in all my courses, we have mostly focused on output within the console which is something I would like to develop. I would like to enhance my 
code to include the ability to output the data via printer or into a file that can be read by some browser or other window that can be styled to read better.
Were this a true banking application there would be branding requirements and other needs that were not met.  If we were truely modeling a bank account, we would
need to build in functions that would check if the user is logged in and if that user was the accuont owner or bank associate. There are so many options that could
be added to this basic application that it is impossible to pinpoint what direction I would go in without more information from the end user or bank client.

//Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

One of the things that I struggled with at first was generating a formatted output. I knew that it was not a great option to manually insert whitespace between
data to format a chart but this is something that we had not addressed directly in any of my course work and I needed to do some research to find the best
method to execute this task.  At first, I found a function that would set the x and y position of the cursor prior to executing cout which seemed to be the answer
but as I continued on to executing this function I learned that it was implementing outdated code that probably wasn't the most ideal solution so, after doing 
a little more research on the evolution of this outdated code, I found that there was a better and more streamlined method to execute this whitespace requirement.

//What skills from this project will be particularly transferable to other projects or course work?

From this project, my biggest moment of realization was to do with Classes and how they work. In a smaller application that doesn't contain an object class, I 
believe I can visualize how a variable moves through a program particularly well and the introduction of object classes has thrown me off a bit. This project 
helped me to get clarity on how a class truly function and, while I am still learning the standards, I believe that I am better able to visualize a variable moving 
through an object better.  Further, I am better understanding debugging within visual studio to help figure out where those variables get lost as a problem arises
which is mostly where the errors I experienced during the debugging process.

//How did you make this program maintainable, readable, and adaptable?

Considerations were made while writing the code for this project to adhere to the standards provided in the requirements documentation and I appreciate that many
of these requirements are industry standard but I also realized that it is possible that each company will have their own requirements for standard naming of variables,
methods, classes etc.  I further have developed my skills to simplify my code by recognizing when to build a function to execute repeated code. To this end, I have 
also learned that, outside of class memebers, functions should be declared and defined outside of the main function which was something I learned in this project as well.
Finally, with some room for improvement, I have documented my code with comments throughout to explain the purpose of the function or class. After feedback, I realize that 
in this project I did not define the member functions within my class and although it was a miss here, I now know that these comments should extend throughout all areas of 
code.
