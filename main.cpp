#include <SFML/Graphics.hpp>
#include <time.h>
#include <chrono>
#include <thread>
#include<iostream>


// Method declarations
void shuffle();
void display(int index, int delay);
void swap(int* a, int* b);
void selectionSort();
void insertionSort();
void merge_sorted(int p, int q, int r);
int  partition(int p, int q);
void mergeSort(int start, int end);
void quickSort(int p, int q);
void bubbleSort();
void Force_close();

// Global Variables
sf::RenderWindow viewport(sf::VideoMode(1200, 600), "Algo-Visualizer");
int rects[100];
bool sorted;
sf::Font font;
sf::Text text;



int main()
{
    if(!font.loadFromFile("Arial.ttf"))
{
    std::cout<<"ERROR"<<std::endl;
    return 0;
}
text.setFont(font);
text.setString("HELLO");
text.setCharacterSize(15);
text.setFillColor(sf::Color::White);
viewport.draw(text);
    srand(time(NULL));

    shuffle();

    while (viewport.isOpen())
    {
        sf::Event e;
        while (viewport.pollEvent(e))
        {
            // Closes the window and ends the program
            if (e.type == sf::Event::Closed)
            {
                viewport.close();
                return 0;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                viewport.close();
                return 0;
            }

            // Runs insertion sort
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) 
            {
                shuffle();
                insertionSort();
                display(0, 10);
                sorted = true;
            }
            
            // Runs merge sort
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) 
            {
                shuffle();
                mergeSort(0, 99);
                display(0, 10);
                sorted = true;
            }

            // Runs quick sort
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                shuffle();
                quickSort(0, 99);
                display(0, 10);
                sorted = true;
            }

          

            // Runs selection sort
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                shuffle();
                selectionSort();
                display(0, 10);
                sorted = true;
            }

            // Runs bubble sort
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                shuffle();
                bubbleSort();
                display(0, 10);
                sorted = true;
            }
            
            // shufffle
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) shuffle();   

        
            
        }
    }

    
}
void Force_close()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                viewport.close();
               return;
            }
}
// Shuffles the number bars
void shuffle()
{
    sorted = false;
    for (int i = 0; i < 100; i++)
    {
        rects[i] = (rand() % 500);
    }

    display(0, 10);
}

// Displays the number bars and changes the colors
void display(int index, int delay)
{
    viewport.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    for (int i = 0; i < 100; i++) {
        sf::RectangleShape bar(sf::Vector2f(10, rects[i]));
        bar.setPosition(i * 12, 600 - rects[i]);
        bar.setFillColor(sorted || i == index ? sf::Color::Green : sf::Color::White);
        viewport.draw(bar);
    }

    viewport.display();
}

// Plays the sound that correlates to the bar being interacted with

// swaps two elements in the array
void swap(int* a, int* b)
{
    auto temp = *a;
    *a = *b;
    *b = temp;
}

// Best: O(n^2), Worst: O(n^2), Average: O(n^2)
void selectionSort() {
    int minIndex = 0;

    for (int i = 0; i < 99; i++)
    {
        minIndex = i;
    Force_close();
        for (int j = i+1; j < 100; j++)
        {   Force_close();
            if (rects[j] < rects[minIndex])
            {
                minIndex = j;
                display(j, 10);
            
            }
        }

        display(i, 10);
        
        swap(&rects[minIndex], &rects[i]);
    }
}

// Best: O(n), Worst: O(n^2), Average: O(n^2)
void insertionSort()
{
    int key, i, j;

    for (i = 0; i < 100; i++)
    {   Force_close();
        key = rects[i];
        j = i - 1;

        while (j >= 0 && rects[j] > key)
        {   Force_close();
            rects[j + 1] = rects[j];
            j = j - 1;
            display(j, 10);
           
        }

        rects[j + 1] = key;
    }
}

// Best: O(nlogn), Worst: O(nlogn), Average: O(nlogn)
void merge_sorted(int s, int m, int e)
{
    int i=0, j = 0, size_left = m-s+1, size_right = e-m, merge_at =s;
    int left[size_left] , right[size_right];
   for(int k=0 ; k<std::max(size_left, size_right) ; k++)
   {    Force_close();
        if(k < size_left)
        {
            left[k] = rects[k+s];
        }
        if(k < size_right)
        {
            right[k] = rects[k+m+1];
        }
   }
   while(i<size_left && j<size_right)
   {    Force_close();
    if(left[i] < right[j])
    {
        rects[merge_at] = left[i++];
        display(merge_at ,10);
        merge_at++;
        
        
    }
    else 
    {   rects[merge_at] = right[j++];
    display(merge_at, 10);
    merge_at++;
    
    }
   }

    while(j<size_right)
    {   Force_close();
        rects[merge_at] = right[j++]; 
        display(merge_at ,10);
        merge_at++;
       
    }
   
   
    while( i< size_left)
    {   Force_close();
        rects[merge_at] = left[i++];
        display(merge_at, 10);
        merge_at++;
     
    }
}

void mergeSort(int const start, int const end)
{
    if (start >= end) return;
    Force_close();
    int mid = start + (end - start) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge_sorted(start, mid, end);
}


void quickSort(int p, int r)
{   Force_close();
    if (p < r)
    {
        int q = partition(p, r);

        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int partition(int p, int r)
{
    int pivot = rects[r];
    int i = (p - 1);

    for (int j = p; j <= r; j++) 
    {   Force_close();
        if (rects[j] < pivot)
        {
            display(i, 10);
            swap(&rects[++i], &rects[j]);
            display(i, 10);
           
        }
    }

    display(i, 10);
    swap(&rects[i+1], &rects[r]);
    display(i, 10);

    return i+1;
}


// Best: O(n), Worst: O(n^2), Average: O(n^2)
void bubbleSort()
{
    int i, j;
    bool swapped;

    for (i = 0; i < 99; i++)
    {   Force_close();
        swapped = false;
        for (j = 0; j < 99 - i; j++)
        {   Force_close();
            if (rects[j] > rects[j + 1])
            {
                swap(&rects[j], &rects[j + 1]);
                display(j, 1);
             
                swapped = true;
            }
        }

        // If not swapped by inner loop 
        if (!swapped) break;
    }
}