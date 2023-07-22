# dtocpp

_Data-Transfer-Object_

## Objective

Origin of the consideration is it, how one could read in best, without much expenditure an XML configuration file. 
Let's take a look at both options.

*XML*
<Data Value1=“0“ Value"1"\>       

*CPP*
struct Data {
   int mValue = 0;
   int mValue = 1;
};

If one compares both variants, one recognizes similarities. 

* An object. In XML it is the element and in CPP the structure / class.
* One or more values. In XML it is the attributes and in CPP the member variables.

In XML and correspondingly in CPP the whole thing can be deepened one level further. Let's add one more element.

    *XML*                                       *CPP*
    <Data Value1=“0“ Value"1"\>                 struct Data {
                                                   int mValue = 0;
                                                   int mValue = 1;
                                                };

If one compares both variants, one recognizes similarities. 

* An object. In XML it is the element and in CPP the structure / class.
* One or more values. In XML it is the attributes and in CPP the member variables.

In XML and correspondingly in CPP the whole thing can be deepened one level further. Let's add one more element.

    *XML*                                       *CPP*
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
Schauen wir uns mal beide Möglichkeiten an.

    *XML*                                       *CPP*
    <Data Value1=“0“ Value"1"\>                 struct Data {
                                                   int mValue = 0;
                                                   int mValue = 1;
                                                };
    
Vergleicht man beide Varianten so erkennt man Gemeinsamkeiten. 

* Ein Objekt. In XML ist es das Element und in CPP die Struktur / Klasse.
* Ein oder mehrer Werte. In XML sind es die Attribute und in CPP die Member Variablen.

Man kann in XML und entsprechend in CPP das ganze um eine Stufe weiter vertiefen. Fügen wir als noch ein Element hinzu.

    *XML*                                       *CPP*
                                                struct OtherData {
                                                    std::string mName = "Fox";
                                                };
    <Data Value1=“0“ Value"1">                  struct Data {
                                                    int mValue = 0;
                                                    int mValue = 1;
        <OtherData Name="Fox"\>                     OtherData mOtherData;
    <\Data>                                     };
    

    


