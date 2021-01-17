#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double compute(double letters, double words, double sentences);
void print_results(double index);

int main()
{
    double l, s, w = 1, index;

    //Grade 1
    // char text[] = "One fish. Two fish. Red fish. Blue fish.";

    //Grade 2
    // char text[] = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";

    //Grade 3
    // char text[] = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";

    //Grade 5
    // char text[] = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";

    //Grade 7
    // char text[] = "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.";

    //Grade 8
    // char text[] = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, \"and what is the use of a book,\" thought Alice \"without pictures or conversation?\"";

    //Grade 9
    // char text[] = "There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.";

    // //Grade 10
    // char text[] = "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.";

    //Grade 16+
    char text[] = "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.";

    for (int i = 0; i < strlen(text); ++i)
    {
        //if its a letter add to letter counter
        if (isalpha(text[i]))
            l++;
        //if its contains a sentence ending add to the sentence counter
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            s++;
        //if its space add to "word" counter...word counter is already set to 1 to account for the last word.
        if (isspace(text[i]))
            w++;
    }

    index = compute(l, w, s);

    print_results(index);

    return 0;
}

double compute(double letters, double words, double sentences)
{
    return (round((0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8));
}

void print_results(double index)
{
    if (index <= 0) printf("GRADE: %i\n", 1);
    
    else if (index >= 16)  printf("GRADE: 16+\n");

    else printf("GRADE: %i\n", (int)index);
}
