# Schéma
## Baterie
Baterie je z jednoho starého notebooku. Jeho stardantní napětí je od 13V po 9V. S touhle nastabilitou napětí mám špatnou zkušenost a tak jsem si zkusil vyvinout zařizení, které mi umožní mít stabilní výkon na moterech...
## Vypinač
Standartní 3A výpinač.
## Dioda
Ochraná dioda proti přepolování.
## Zdroj 5V
7805 napájí jak logickou čast. USB na BluePillu.
## Zdroj 3,3V
LF33CV napájí logickou část i vstup na port PB4, indikuje napajení.
## XL6009
Tento obvod má na výstupu několikrát větší napětí, než je na vstupu. Obvod je nastavený na nasobení kolem 1,5 .
U_out=1,5*U_in
## Kondenzátory
Zde jsem ho vytvořil z velkého množstvý starých kondenzátorů zapojených paralerně. Mám zde kapacitu kolem 3mF. Vytvořil jsem tím mezizdroj, který by měl pokrýt proudové špičky, které jsou při rozjiždění motoru.
## H-Můstek
H-můstek je z obvodu L298N pro až 2A na výstupu.
## Motory
Jedná se o standartní motory pro asi 7V, ale teprve při 10V na svorkách motoru máji ten správný tah.
Specifikací jednoho motoru je, že má rozbitou převodovku. Překluzuje železná hřídel. To má za následek, že lze mechanicky zatížit jen jednu stranu výstupní hřídele.