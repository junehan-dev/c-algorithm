1. what are the basic modules of a C program called?

   - entry point function(main)
   - header

      - importing libraries
      - declaring prototypes

#. what is a syntax error?

   - an error which has mistakes in expression those make the program work.
   - semicolon, declaration, comment, function expression, data assignment.

#. what is semantic error?

   - an error which make program work in wrong way, and does not captured by complier.
   - wrong value assignment, things breaks readability(name convention), wrong operator uses.

4. help code below

   .. code-block:: c

      include studio.h
      int main{void} /* this prints the number of weeks in a year /*
      (
      int s

      s := 56;
      print(There are s weeks in a year.);
      return 0;

   .. code-block:: c

      #include <stdio.h>

      int   main(void) /* this prints the number of weeks in a year /*
      {
         int weeks;

         weeks = 56;
         printf("There are %d weeks in a year.", weeks);
         return 0;
      }

#. which of the following are c keywords? *main, int, function, char, =*

   - main: name (identifier)
   - int: keyword (data type)
   - function: concept (idea)
   - char: keyword (data type)
   - =: assignment (operator)

#. how would you print the values of the variables ``words`` and ``lines`` so they appear in the following form:

   ::

      There were 3020 words and 350 lines.

      Here, 3020 and 350 represent the values of the two variables.

   .. code-block:: c

      #include <stdio.h>

      int   main(void)
      {
         int		words, lines;
         char	*line_break;

         words = 3020;
         lines = 350;
         line_break = "\n\n";

         printf(
            "There were %d words and %d lines.%sHere, %d and %d represent the values of the two variables.%s",
            words, lines, line_break, words, lines, line_break
         );

         return (0);
      }

