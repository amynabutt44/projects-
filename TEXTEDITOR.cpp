#include <iostream>
#include <string>
#include <stack>
using namespace std;

class TextEditor {
private : 
    string text;
    stack<string> undostack;
    stack <string> redostack;
public:
    TextEditor()
    {
        text = "";
    }
    void  insert(string texttotransform)
    {
        // sub sa pehla hum text ki pehla wali form ko store kareya geya
        undostack.push(text);
        // text ma hum new cotent store karavana lagye haan 
        text += texttotransform;

    }
    void undo()
    {
        cout << " undo operation is working" << endl;
        if (!undostack.empty())
        {
            // hum na pehla current state ko save kiya 
            redostack.push(text);
           text = undostack.top();
            undostack.pop();
            

        }

    }
    void redo()
    {
        cout << " redo operation is working" << endl;
        // hum na ab undo ma save karvna haan taka humeya pata hoo 
        if (!redostack.empty())
        {
            undostack.push(text);
            text = redostack.top();
            redostack.pop();
        }
        
        
    }
    void display()
    {
        cout << "     " << text << "     " << endl;
    }
   
};

int main() {
    TextEditor editor;

    editor.insert("Hello, ");
    editor.insert("world!");
    editor.display();

    editor.undo();
    editor.display();

    editor.redo();
    editor.display();
    editor.undo();
    editor.display();
    editor.undo();
    editor.display();
 

    return 0;
}
