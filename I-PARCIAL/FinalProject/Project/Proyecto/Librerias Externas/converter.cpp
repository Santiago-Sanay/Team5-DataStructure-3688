/**************************
 * Headers
 **************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "pdf.h"
#include "converter.h"


using std::ostringstream;
using std::ifstream;
using std::complex;
using std::cout;
using std::endl;
using std::ios;
void hacerPdf(string s,int wrap);

/**************************
 * Local Functions
 **************************/

// ---------------------------------------------------
// Multiply degrees by (2 * pi / 360.0) to
// obtain radians
// ---------------------------------------------------

static double degreesToRadians(int degrees)
{
   return((3.14159 / 180.0) * degrees);
}

// ---------------------------------------------------
// Read 'fileName' and populate 'lines' with its
// contents (on success, return true).  On error,
// populate 'errMsg' and return false.
// ---------------------------------------------------

static bool getLines(
   const string   &fileName,
   vector<string> &lines,
   string         &errMsg
)
{
   ifstream in;

   in.open(fileName.c_str(), ios::binary);

   if(!in)
   {
      errMsg = "Could not open: [" + fileName + "]";
      return(false);
   }

   string line = "";

   for(;;)
   {
      char c = (char)in.get();

      if(in.eof())
      {
         if(line != "")
            lines.push_back(line);

         break;
      }

      line += c;

      if(c == '\n')
      {
         lines.push_back(line);
         line = "";
      }
   }

   in.close();

   return(true);
}

// ---------------------------------------------------
// Draw 'theText' at: [x, y] (using the specified
// font and font size) with a box around it
// ---------------------------------------------------

static void drawBoundedText(
   const string &theText,
   int           x, 
   int           y,
   PDF::Font     theFont,
   int           fontSize,
   PDF          &p
)
{
   p.setFont(theFont, fontSize);

   p.showTextXY(theText, x, y);

   int width = PDF::stringWidth(
      theFont, fontSize, theText
   );

   int offset = (int)(0.4 * fontSize + 0.5);

   p.drawRect(x, y - offset, width, fontSize + offset);
}

// ---------------------------------------------------
// Demonstrate:
//
//    - text wrapping
//    - drawing and filling of circles and ellipses
//    - drawing and filling of rectangles and polygons
//    - drawing lines, using different line widths
//    - use of images
// ---------------------------------------------------

static void demoOne(PDF& p, string s,int wrap)
{


    p.setFont(PDF::HELVETICA, 12);
    vector<string> sv = p.wrapText(s, wrap, true);

    for (int i = 0, n = sv.size(); i < n; i++)
    {
        // cout << "sv[" << i << "][" << sv[i] << "]\n";
        p.showTextXY(sv[i], 80, 745 - 20 * i);
    }

}

void hacerPdf(string s,int wrap)
{
    typedef void (*DemoFunction)(PDF&,string s,int wrap);

    DemoFunction functions[] =
    {
        demoOne
    };

    int n = sizeof(functions) / sizeof(functions[0]);

    for (int i = 0; i < n; i++)
    {
        ostringstream out;

        out << "tabla" << i << ".pdf";

        string fileName = out.str();

        cout << "-----------------------------------------" << "\n";
        cout << "Creating File: [" << fileName << "]" << "\n";
        cout << "-----------------------------------------" << "\n";

        PDF pdf;

        functions[i](pdf,s,wrap);

        string errMsg;

        if (!pdf.writeToFile(fileName, errMsg))
        {
            cout << errMsg << endl;
        }
        else
        {
            cout << "(File Successfully Written)" << endl;
        }

        cout << endl;
    }
}

void HacerPdf(std::string s)
{
}
