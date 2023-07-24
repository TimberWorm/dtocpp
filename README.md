# dtocpp

_Data-Transfer-Object_

## Objective

Origin of the consideration is it, how one could read in best, without much expenditure a XML configuration file. 
Let's write XML and C++ side by side:

    *XML*                                       *C++*
    <Data Value1=“0“ Value"1"\>                 struct Data {
                                                   int mValue = 0;
                                                   int mValue = 1;
                                                };

If one compares both variants, one recognizes similarities. 

* An object. In XML it is the element and in CPP the structure / class.
* One or more values. In XML it is the attributes and in CPP the member variables.

In XML and correspondingly in C++ the whole thing can be deepened one level further. Let's add one more element.

    *XML*                                       *C++*
                                                struct OtherData {
                                                    std::string mName = "Fox";
                                                };
    <Data Value1=“0“ Value"1">                  struct Data {
                                                    int mValue = 0;
                                                    int mValue = 1;
        <OtherData Name="Fox"\>                     OtherData mOtherData;
    <\Data>                                     };
    <\Data>

# German

Daten-Transfer-Objekt

## Zielsetzung

Ursprung der Überlegung ist es, wie man am besten, ohne viel Aufwand eine XML Konfigurationsdatei einlesen könnte. 
Schreiben wir mal XML und C++ nebeneinander:

    *XML*                                       *C++*
    <Data Value1=“0“ Value"1"\>                 struct Data {
                                                   int mValue = 0;
                                                   int mValue = 1;
                                                };
    
Vergleicht man beide Varianten so erkennt man Gemeinsamkeiten. 

* Ein Objekt. In XML ist es das Element und in CPP die Struktur / Klasse.
* Ein oder mehrere Werte. In XML sind es die Attribute und in CPP die Member Variablen.

Man kann in XML und entsprechend in C++ das ganze um eine Stufe weiter vertiefen. Fügen wir als noch ein Element hinzu.

    *XML*                                       *C++*
                                                struct OtherData {
                                                    std::string mName = "Fox";
                                                };
    <Data Value1=“0“ Value"1">                  struct Data {
                                                    int mValue = 0;
                                                    int mValue = 1;
        <OtherData Name="Fox"\>                     OtherData mOtherData;
    <\Data>                                     };
    

    


