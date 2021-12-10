#include <iostream>
#include <fstream>
#include<string>
using namespace std;

string getString(string msg){
    cout<<msg;
    string n;
    getline(std::cin, n);
    return n;
}
int getInt(string msg){
    cout<<msg;
    int n;
    cin>>n;
    std::cin.ignore(1,'\n');
    return n;
}
string getTag(string type) {
    string paragraph;
    string sentence;
    do {
        getline(std::cin, sentence);
        if (!sentence.empty()) {
            sentence = sentence + "<br>";
        }
        paragraph = paragraph + sentence;
    } while (!sentence.empty());
    return "<" + type + ">" + paragraph + "</" + type + ">";
}
string getInput()
{
    string ivestis= getString(" Prasome ivesti lauko id: ");
    ivestis="<input type='text' name='"+ivestis+"' value='' ><br>";
    return ivestis;
}
string createHeading()
{
    cout<<" Iveskite antraste: "<<endl;
    string heading=getTag("h");
    return heading;
}
string createButton(){
    string button;
    button+=getString("Iveskite mygtuka");
    return "<button class='button'><black>"+button+"</button>";
}
string createForm(){
    string adresas,form;
    bool run=true;
    adresas= getString(" Prasome ivesti formos adresa: ");
    form="<form method='POST' action='"+adresas+"'>";
    while (run==true) {
        cout << " Koki formos elementa noretumete sukurti? " << endl;
        int n=getInt(" 1 - Label\n 2 - Edit\n 3 - Uzbaigti\n");
        switch (n) {
            case 1:
                cout<<" Label: ";
                form+=getTag("label");
                break;
            case 2:
                form+=getInput();
                break;
            case 3:
                run=false;
                break;
            default:
                cout << " Ivedete klaidinga reiksme " << endl;
                break;
        }
    }
    form+=createButton();
    form+="</form>";
    return form;

}
string createParagraph(){

    cout<<" Iveskite paragrafo turini: "<<endl;
    std::cin.ignore(1,'\n');
    return getTag("p");

}
string createNavigation(){
    string navigation, list;
    bool vykdyti=true;
    while (vykdyti==true) {
        int n;
        n=getInt(" 1 - Sukurti nuoroda\n 2 - Uzbaigti\n");
        switch (n) {
            case 1:
                navigation+="<li><a href='#'>"+getString(" Iveskite zyme: ")+"</a></li>";
                break;
            case 2:
                vykdyti=false;
                break;
            default:
                cout << " Ivedete klaidinga reiksme " << endl;
                break;
        }

    }
    navigation="<section><nav><ul>"+navigation+"</ul></nav></section>";
    return navigation;
}

string createTable() {
    int st, eil, i, j;
    string eilute, eile, lentele;
    st= getInt("iveskite stulpeliu skaiciu: ");
    eil=getInt("iveskite eiluciu skaiciu: ");
    for (j = 1; j <= eil; j++) {
        eilute="";
        cout << "Pildysime " << j << " eilute" << endl;
        for (i = 1; i <= st; i++) {
            cout << "Irasykite " << i << " stulpelio turini " << endl;
            eilute = eilute + getTag("td");
        }
        lentele = lentele + "<tr>" + eilute + "</tr>";
    }
    return "<table>" + lentele + "</table>";
}
int main() {
    ofstream output;
    output.open("index.html", ios::trunc);
    output<<"<!DOCTYPE html>\n";
    output<<"<html>\n"
            "<head>\n";
    output<<"<section><style>"
            "p{"
            "margin-left: 200px;"
            " text-align: left; \n"
            "            width: 600px;\n"
            "            height: 800px;\n"
            "}";
    output<<"table{\n"
            "  width:50%;\n"
            "  table-layout: fixed;\n"
            "  margin-left: auto; \n"
            "  margin-right: auto;\n"
            "}\n"
            ".tbl-header{\n"
            "  background-color: rgba(255,255,255,0.3);\n"
            " }\n"
            ".tbl-content{\n"
            "  height:300px;\n"
            "  overflow-x:auto;\n"
            "  margin-top: 0px;\n"
            "  border: none//1px solid rgba(255,255,255,0.3);\n"
            "}\n"
            "td{\n"
            "  background: -webkit-linear-gradient(left, white, black);\n"
            "  background: linear-gradient(to right, white, black);\n"
            "  font-family: 'Roboto', sans-serif;\n"
            "  padding: 15px;\n"
            "  text-align: left;\n"
            "  vertical-align:middle;\n"
            "  font-weight: 300;\n"
            "  font-size: 16px;\n"
            "  color: black;\n"
            "  border-bottom: solid 1px rgba(255,255,255,0.1);\n"
            "}\n"
            "\n"
            "\n"
            "/* demo styles */\n"
            "\n"
            "@import url(https://fonts.googleapis.com/css?family=Roboto:400,500,300,700);\n"
            "body{\n"
            "background: linear-gradient(left, white, black);\n"
            "  background: linear-gradient(to right, white, black);\n"
            "}\n"
            "section{\n"
            "  margin: 50px;\n"
            "}\n"
            "\n"
            "\n"
            ".made-with-love {\n"
            "  margin-top: 40px;\n"
            "  padding: 10px;\n"
            "  clear: left;\n"
            "  text-align: center;\n"
            "  font-size: 10px;\n"
            "  font-family: arial;\n"
            "  color: #fff;\n"
            "}\n"
            ".made-with-love i {\n"
            "  font-style: normal;\n"
            "  color: #F50057;\n"
            "  font-size: 14px;\n"
            "  position: relative;\n"
            "  top: 2px;\n"
            "}\n"
            ".made-with-love a {\n"
            "  color: #fff;\n"
            "  text-decoration: none;\n"
            "}\n"
            ".made-with-love a:hover {\n"
            "  text-decoration: underline;\n"
            "}\n"
            "\n"
            "\n"
            "/* for custom scrollbar for webkit browser*/\n"
            "\n"
            "::-webkit-scrollbar {\n"
            "    width: 6px;\n"
            "} \n"
            "::-webkit-scrollbar-track {\n"
            "    -webkit-box-shadow: inset 0 0 6px rgba(0,0,0,0.3); \n"
            "} \n"
            "::-webkit-scrollbar-thumb {\n"
            "    -webkit-box-shadow: inset 0 0 6px rgba(0,0,0,0.3); \n"
            "}</style>"
            "</head>";
    output<<"<meta name='viewport' content= width=device-width, initial-scale= 1>\n"
            "<style>\n"
            ".button {\n"
            "  background-color: #555555; /* Green */\n"
            "  border: none;\n"
            "  color: white;\n"
            "  padding: 15px 32px;\n"
            "  text-align: center;\n"
            "  text-decoration: none;\n"
            "  display: inline-block;\n"
            "  font-size: 16px;\n"
            "  margin: 4px 2px;\n"
            "  cursor: pointer;\n"
            "}"
            "* {\n"
            "  box-sizing: border-box;\n"
            "}\n"
            "\n"
            "body {\n"
            "  margin: 0;\n"
            "  font-family: Arial, Helvetica, sans-serif;\n"
            "}\n"
            "\n"
            "/* Style the side navigation */\n"
            ".sidenav {\n"
            "  height: 100%;\n"
            "  width: 200px;\n"
            "  position: fixed;\n"
            "  z-index: 1;\n"
            "  top: 0;\n"
            "  left: 0;\n"
            "  background-color: #111;\n"
            "  overflow-x: hidden;\n"
            "}\n"
            "\n"
            "\n"
            "/* Side navigation links */\n"
            ".sidenav a {\n"
            "  color: white;\n"
            "  padding: 16px;\n"
            "  text-decoration: none;\n"
            "  display: block;\n"
            "}\n"
            "\n"
            "/* Change color on hover */\n"
            ".sidenav a:hover {\n"
            "  background-color: #ddd;\n"
            "  color: black;\n"
            "}\n"
            "\n"
            "/* Style the content */\n"
            ".content {\n"
            "font - size 50px;\n"
            "  margin-left: 200px;\n"
            "  padding-left: 20px;\n"
            "}\n"
            "background: linear-gradient(left, white, black);\n"
            "  background: linear-gradient(to right, white, black);\n"
            "</style>\n"
            "</head>\n"
            "<body>\n"
            "\n"
            "<div class=\"content\">\n"
            "  <h2>"+createHeading()+"</h2>\n"
                                     "</div>";
    output<<"<title>Mano pirmas puslapis</title>\n"
            "</head>\n"
            "<body>\n";
    bool vykdyti=true;
    while (vykdyti==true) {
        int n;
        cout << " Koki elementa noretumete sukurti? " << endl;
        n=getInt(" 1 - Paragrafas\n 2 - Lentele\n 3 - Form\n 4 - Navigacija\n 5 - Antraste\n 6 - Uzbaigti\n");
        switch (n) {
            case 1:
                output <<"<div class='p'>"+createParagraph()+"</div>";
                break;
            case 2:
                output <<"<div class='tbl-content'><table cellpadding= '0' cellspacing= '0' border='0'><tbody>"+createTable()+"</div></tbody></section>";
                break;
            case 3:
                output<<"<div class='content'>"+createForm()+"</div>";
                break;
            case 4:
                output <<"<div class='sidenav'>"+createNavigation()+"</div>";
                break;
            case 5:
                output <<"<div class=\"content\"><h2>"+createHeading()+"</h2></div>";
                break;
            case 6:
                vykdyti=false;
                break;
            default:
                cout << " Ivedete klaidinga reiksme " << endl;
                break;
        }
    }
    output<<"</section>";
    output<<"</body>\n</html>\n";
    output.close();

    return 0;
}