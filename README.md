# Driverbot template
I det här repot hittar ni exempel kod att utgå från samt instruktioner när ni kodar i ert projekt.

## GitHub
Acceptera uppgiften på [https://classroom.github.com/a/cqxgjh7K](https://classroom.github.com/a/cqxgjh7K). 

Ett remote repo med de filer som finns i det här repot skapas. Följ stegen nedan för att skapa ett lokalt repo, koppla det till ditt nya remota repo och hämta ned de filer som finns i ditt nya remota repo.

1. Öppna ett terminalfönster, t.ex. ``` git bash``` eller ```powershell```
2. Använd ```cd``` (change directory = byt mapp) för att förflytta dig till den mapp du vill lägga koden i. Du kan skapa en ny mapp direkt i terminalen genom att skriva ```mkdir nya-mappens-namn ``` när du orienterat dig till den plats du vill att den nya mappen ska vara.
3. Kör ```git clone länk-till-ditt-repo-slutar-på-.git ``` 
4. Koden som fanns på GitHub bör nu finnas i din mapp lokalt på datorn. Använd ```ls ``` i terminalen för att se att den inte längre är tom.
5. Testa att redigera en fil eller skapa en ny. (Genom att köra ```code filnamn``` i terminalen kan du öppna en fil i visual studio code direkt från terminalen, om du skriver ett filnamn som inte redan finns så kommer en ny fil att skapas. Du kan göra samma sak med andra program men detta kräver att du vet vad programmets _cmdlet_ är)
6. Skriv ```git add .```i terminalen. Alla filer följs nu av git. (Detta gör du varje gång du har skapat nya filer som du vill följa, OBS! Om du byter ut . mot ett filnamn så läggs bara den specifika filen till.)
7. Skriv ```git commit -m "my first commit"```i terminalen. git har nu noterat de förändringar som skett med filerna. (Detta gör du varje gång du vill spara dina ändringar - endast den lokala delen påverkas).
8. Skriv ```git push``` i terminalen. Du har nu skickat dina uppdateringar till GitHub. Uppdatera web-sidan för att dubbelkolla att dina ändringar syns. (Detta gör du varje gång du vill att dina ändringar ska sparas på GitHubs hemsida).
9. Testa nu att göra en ändring i ditt remota repo (på GitHub). Gå tillbaka till terminalen och skriv ```git pull```. Din lokala kod uppdateras nu så att den matchar de ändringar du gjort online. Dubbelkolla att det blivit rätt! (Detta gör du varje gång du vill få ned de ändringar som gjorts online till ditt lokala repo. T.ex. om du själv redigerat direkt på GitHub, om du arbetat från en annan dator eller om du arbetar i grupp och någon annan har uppdaterat koden.)

### Credentials
Har problem med credentials (du får en prompt om att ange dina inloggningsuppgifter, när du gör detta får du ett felmeddelande om att github inte längre tillåter den typen av inloggning)? Följ stegen nedan (urklipp från [https://github.com/abbindustrigymnasium/testuppgift-f-r-github-vning-grupp-sofies-team](repot med github-instruktioner). Titta i det länkade repot för mer stöd kring git/github.

-------------------------------------------------------------------------
![image](https://github.com/abbindustrigymnasium/driverbot-template/assets/22837762/e457c941-0d7c-405a-b843-d89fb9292fe0)
-------------------------------------------------------------------------


## Mikrokontroller
### Koppla och testa!
Bilden nedan visar hur du ska koppla motorn till din esp.
![image](https://github.com/abbindustrigymnasium/driverbot-template/assets/22837762/703aad4b-4015-4c4a-9739-1644a61969b3)

### Koda
När du löser uppgifterna nedan utgår du från koden i [motorTest.ino](motorTest.ino). Börja med att planera dina lösningar mha psuedokod och/eller diagram innan du skriver den faktiska koden.

1. Läs och tolka koden - vad tror du att den gör? Kommentera i filen. Testa att köra koden för att kontrollera dina antaganden.
2. Koden fungerar inte helt som vi tänkt oss, vi vill att den ska byta körriktning efter 2200 millisekunder och efter 2200 byter igen. I nuläget kör den bara åt ett hål, lös det! Utgå från det du lärde dig om koden i steg 1 och experimentera vid behov vidare genom att ändra olika värden för att se vad varje del gör.
3. Gör om kodstrukturen genom att skapa en funktion/metod ```Drivetest(input1, input2)``` som utför koden från steg 2. Ett anrop av funktionen kan se ut som nedan.
```
Drivetest(motorPinRightDir, motorPinRightSpeed);
```
4. Nu ska vi utöka funktionaliteten i ```Drivetest()```. Kopiera funktionen och döp den nya varianten till ```Drivetest2()```. Nu vill vi se hur snabbt och långsamt motorn kan köra. Skapa en loopande funktion där motorns hastighet succesivt ökar.
5. Vi fortsätter bygga ut funktionaliteten! Utgå från ```Drivetest2()``` och skapa en ny funktion som vi kan kalla ```Drivetest3()```. Den nya funktionen ska kunna göra samma sak som tvåan men alterera mellan vänster och höger varv. Först från långsamt til snabbt på högervarv sedan samma åt vänster sedan höger igen o.s.v...
6. Vi fortsätter bygga på funktionen! I denna version ska du mellan varje varv låta motorn vila några sekunder, du vill även att den i loggen räknar upp hur många varv den har kört.

## MQTT
Jobba utifrån [denna Sway](https://sway.cloud.microsoft/4wekNvX2nqSH0zCX?ref=email&loc=play). 

GitHub repository med exempelkod att arbeta utifrån hittar ni [här](https://github.com/hitachigjoafli/ExempelMQTTkod).

## VUE
Exempelkod i VUE för att skapa en hemsida som driverboten kan styras via finns [här](https://github.com/abbindustrigymnasium/Driverbot/tree/master/Hemsida).
1. Utgå från koden ovan och testa att styra din bil. OBS! Ni behöver konfigurera koden i ```Driverbot.ino``` så att den pekar mot er broker.
2. För högre betyg än godkänt: modifiera den befintliga koden för att på något sätt förbättra resultatet eller bygg en egen hemsida.

Tips på fördjupningar för högre betyg (mer avancerade problem):
- Skapa en karta över driverbotens rörelse för att illustrera hur den har kört
- Byt ut den typ av input som ges via hemsidan till t.ex. en form som driverboten ska följa eller en punkt den ska köra till

🐲🐲
