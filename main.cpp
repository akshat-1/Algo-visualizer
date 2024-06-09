#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;

const int Width = 640;
const int height = 480;
int width_of_element = 4;
int iteration =0;
std::vector<int> arr(Width/width_of_element);

void drawit(RenderWindow& window , int pos , int h)
{
    RectangleShape line(Vector2f(0 , h));
    line.setOrigin(Vector2f(0, h));
    line.setPosition(pos*width_of_element , height);
    if(iteration == pos) line.setFillColor(Color::Red);

    window.draw(line);
}
void algo_used( int i)
{
    int buf =0;
    if(arr[i] > arr[i+1])
    {
        buf = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = buf;
    }
}
int main()
{
    RenderWindow window(VideoMode(640,480), "first", Style::Titlebar | Style::Close | Style::Resize);
    std::srand(unsigned(std::time(nullptr)));
    std::generate(arr.begin(), arr.end(), std::rand);

    for(int i=0 ; i<arr.size(); i++)
    {
        arr[i] = arr[i] /(height*3);

    }
    

    while(window.isOpen())
    {
        Event ev;
        while(window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case Event::Closed:
                window.close();
                /* code */
                break;
            case Event::KeyPressed:
                if(ev.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                break;
            
            }
        }

        window.clear();
        for(int i=0 ; i<arr.size(); i++)
        {
            drawit(window , i , arr[i]);
        }
        window.display();

        algo_used(iteration);
        iteration++;
        if(iteration == arr.size() -1) iteration =0;

    }


    return 0;
}