
$quote "
$ $TOG: dtinfo.msg /main/24 1999/09/20 13:32:47 mgreess $
$ 
$ (c) Copyright 1996 Digital Equipment Corporation.
$ (c) Copyright 1996 Hewlett-Packard Company.
$ (c) Copyright 1996 International Business Machines Corp.
$ (c) Copyright 1996 Sun Microsystems, Inc.
$ (c) Copyright 1996 Novell, Inc.
$ (c) Copyright 1996 FUJITSU LIMITED.
$ (c) Copyright 1996 Hitachi.
$ 
$ ******************************************************************************
$ 

$set	1
$ 
$ messages specific to message-catalog manager
$ 
1 "Message par d�faut introuvable dans le catalogue."


$set	2
$ 
$ messages specific to UAS/DtSearch modules
$ 
1 "La fonction de recherche ``%s'' n'est pas prise en charge."
2 "phrase cit�e"
3 "importance"
4 "proximit�"
$       5       "xor" == Exclusive OR (Boolean)
5 "xor"


$set	4
$ 
$ messages specific to booklist window
$ 
3 "Dtinfo: Liste des livres Biblinfo"
63 "Bienvenue � Dtinfo!"
65 "Section en cours"


$set	5
$ 
$ messages specific to browser window
$ 
1 "Dtinfo: Explorateur"
2 "Pour visusaliser la destination du lien, cliquez sur celui-ci et maintenez-le enfonc�."
3 "Biblioth�que d'informations "

$       4       "The locator for this section is %s"
$       This message is the result of the "Show Locator" operation.
4 "Le point d'implantation de cette section est %s"

$ line-break rules (reserved)
5 ""
6 ""

7 "Le texte s�lectionn� est ins�r� dynamiquement et ne\n\
peut pas �tre utilis� seul pour cr�er l'indication d'un signet.\n\
Vous pouvez s�lectionner un autre texte pr�s du point ou inclure\n\
une plus grande partie du texte qui l'entoure."

$set	6
$ 
$ messages specific to add information library dialog
$ Note: "Infolib" is a CDE glossary term.
$ 

1 "Dtinfo: Ajouter la biblioth�que de documents "

$ 2     "Please enter an absolute path to the Infolib."
$       (Path must exist and include "/".)
2 "Entrez le chemin absolu de la Biblinfo."

$ 3     "Infolib open failed. Check the path specified."
$	(Path passed basic format check, but could not open target found.)
3 "L'ouverture de la Biblinfo a �chou�. V�rifiez le chemin sp�cifi�."

$ 4     "Infolib open failed. Check entry syntax or Infolib integrity."
$       (An unidentified error occurred on attempt to open.)
4 " L'ouverture de la Biblinfo a �chou�. V�rifiez la syntaxe de l'entr�e ou l'int�grit� de Biblinfo."

$ 5     "Infolib specification format error."
5 "Erreur du format de sp�cification de Biblinfo."

$ 6     "No Infolib specified."
6 "Aucune Biblinfo sp�cifi�e."

$ 7     "No Infolib found or specified."
7 "Aucune Biblinfo trouv�e ou sp�cifi�e."

$ 10    "Dtinfo: Infolib Selection"
$       (For title to the File Selection Dialog)
10 "Dtinfo: S�lection Biblinfo"

$ 11    "No Infolibs Present"
$       (This string will be shown in a directory listing where there
$        are no Infolibs found in the directory.)
11 "Pas de biblinfo"


$set	7
$ 
$ dtinfo GUI label strings
$ 
1 "Fichier"
2 "F"
4 "Visualiser"
5 "V"

$	6	"Clone"
$ "Clone" is applied to the selected entry in the booklist, and
$ has the effect of opening another (secondary) window with a
$ copy of the booklist hierarchy below the selection, and rooted
$ (based) at the selected item.
$ [Currently, this functionality is deferred beyond CDE 2.0.]
6 "Clone"
$	7	"N" for "N" in "Clone"
7 "N"

8 "Imprimer"
9 "r"
10 "Imprimer..."
11 "p"
12 "Fermer"
13 "e"
14 "Quitter"
15 "Q"
16 "Editer"
17 "E"
18 "Copier"
19 "C"
20 "Ajouter... "
21 "j"
22 "Supprimer"
23 "i"
24 "Options"
25 "O"
26 "Pr�f�rences..."
27 "c"
28 "Historique automatique"
29 "m"
30 "Afficher la barre d'outils"
31 "b"
32 "Afficher la zone de recherche"
33 "z"
34 "Fen�tres"
35 "r"
36 "Carte graphique"
37 "G"
38 "Section Historique"
39 "H"
40 "Liste des signets"
41 "n"

$	42	"Search History " presents a dialog listing
$ a history of prior search results, as provided in the Search
$ Results Dialog.
42 "Historique de la recherche"
43 "q"
44 "Editeur de requ�tes"
45 "s"
46 "Editeur d'�tendue"
47 "u"
48 "Aide"
49 "A"
50 "Sur l'�l�ment..."
51 "t"
59 "Rechercher:"
61 "Editeur d'�tendue"

$  Messages 62-77 for "Browser" pulldown menu entries
$ 
62 "Explorateur"
63 "E"
64 "Nouvelle fen�tre "
65 "N"
66 "Ouvrir le point d'implantation..."
67 "v"
68 "Afficher le point d'implantation"
69 "f"
70 "Imprimer"
71 "r"
72 "Imprimer..."
73 "p"
74 "Fermer"
75 "e"
76 "Quitter"
77 "Q"

$	78	"On Selection", where selection is a text
$ selection that will be used directly as a search query string
78 "Sur la s�lection"
79 "S"

80 "Editeur de requ�tes"
81 "E"
82 "Editeur d'�tendue"
83 "l"
84 "Historique de la recherche"
85 "H"
86 "Effacer correspondances"
87 "f"
88 "Pr�c�dent (Historique)"
89 "t"
90 "Suivant (Historique)"
91 "s"
92 "Historique..."
93 "q"
94 "Section pr�c�dente"
95 "p"
96 "Section suivante"
97 "v"

$   Messages 98-101 are for traversal of the document view in order
$ to present and highlight the Previous or Next "search hit" (if any)
$ in the section. Presumably, all search hits have already been
$ highlighted to some degree, and this will add the equivalent of a
$ keyboard traversal highlight to the appropriate one when brought
$ into view.
98 "Recherche pr�c�dente"
99 "R"
100 "Recherche suivante"
101 "n"

102 "Rechercher"
103 "R"

$	104	"Go" is a pulldown menu label, where menu items are
$ various methods by which the user may "go" to a specific document.
104 "Aller"
105 "l"

$   Message 106-119 are for the "Marks" pulldown menu
106 "Rep�res"
107 "R"
108 "Cr�er un signet"
109 "t"
110 "Cr�er une note..."
111 "�"

$	112	"List Marks" means to show all saved Marks as a list
$ in a separate dialog window.
112 "Lister les signets"
113 "L"

114 "Modifier la s�lection..."
115 "M"
116 "D�placer la s�lection"
117 "D"
118 "Supprimer la s�lection"
119 "u"

$   Messages 120-129 are for "Options" pulldown menu entries
120 "Options"
121 "O"
122 "Pr�f�rences..."
123 "c"

$	124	"Detach Graphic" removes a selected graphic from the
$ document flow and places it in its own window. A "placeholder"
$ remains in the document where the graphic originally appeared.
124 "D�tacher le graphique"
125 "h"

126 "Afficher la barre d'outils"
127 "b"
128 "Afficher la zone de recherche"
129 "z"

$   Messages 130-135 are for "Windows" pulldown menu entries
130 "Fen�tres"
131 "F"
132 "Liste des livres"
133 "l"
134 "Carte graphique"
135 "C"

$   Messages 136-142	are believed to be *unused*/obsolete
136 "Auteur"
137 "A"
138 "Obtenir un point d'implantation"
139 "D�boguer"
140 "D"
141 "Cr�er une fausse Infobase "
142 "Processus de commande"

$   Messages 143-158 are Help pulldown menu entries, and
$ should of course read the same across all CDE applications,
$ within a localization. They always mean the same thing:
$ provide "help On []"
143 "Aide"
144 "A"
145 "Sur de l'�l�ment..."
146 "m"
147 "A propos de la fen�tre"
148 "s"
149 "A propos de l'application"
150 "n"
151 "Index"
152 "I"
153 "A propos de l'aide"
154 "d"
155 "A propos des cl�s"
156 "o"
157 "A propos de la version"
158 "V"

$	159	"Retain" is believed to be unused
159 "Conserver"

160 "Chemin Biblinfo:"
161 "Ok"
162 "Annuler"
163 "Nom"
164 "Notes"
165 "Afficher"

$	166	"Panner" is a graphical user interface control for
$ selecting that part of a larger area which the associated view
$ window is to display.
166 "Case panoramique"

167 "Attacher"
168 "Afficher la section"

$   Messages 169-182 are for the window which is used to present a
$ detached graphic.
$	169	Fit >graphic< to window
169 "Adapter � la fen�tre"
$	170	Fit >window< to graphic
170 "Adapter au graphique"
171 "25 %"
172 "50 %"
173 "100 %"
174 "125 %"
175 "150 %"
176 "200 %"
$	177	"Custom" value entry for re-scaling of graphic
177 "Personnaliser..."

$   Messages 178-182 refer to where the panner is to be placed within
$ the detached graphic dialog window. Is a "panner" masculine or
$ feminine ? "Beats" me ;-).
178 "Aucune"
179 "Coin sup�rieur gauche"
180 "Coin sup�rieur droit"
181 "Coin inf�rieur gauche"
182 "Coin inf�rieur droit"

183 "Supprimer"
184 "Livre"
185 "Section"
186 "Pr�f�rences:"
187 "Exploration "
188 "Carte"
189 "Recherche "
190 "G�om�trie de l'explorateur"
191 ". . ."
192 "Echelle de la police"

$	193	"Pin []" is a verb
193 "Ancrer la fen�tre"
194 "Enregistrer une erreur"
195 "G�om�trie de la carte"
196 "Mise � jour automatique"
197 "Taille de l'historique de la section"
198 "Taille de l'historique de la recherche"
199 "Maximum  de correspondances"
200 "Affichage automatique de la premi�re correspondance"
201 "Appliquer"
202 "Restaurer"
203 "En fonction"
204 "Hors fonction"
205 "Nombre de sections"
206 "S�lectionn�:"
207 "A imprimer:"
208 "Erreur."
209 "A imprimer"
210 "Sections"
211 "Hi�rarchie"
212 "Nom de l'�tendue"
213 "Sans nom"
214 "Livres"
215 "El�ments"
216 "Nouveau"
217 "Sauvegarder"
218 "Renommer"
219 "Extrait:"
220 "Etendue:"
221 "Requ�te:"
222 "Entrer un point d'implantation unique:"
223 "Supprimer"
224 "Couper"
225 "Coller"
226 "Grouper"
227 "D�grouper"
228 "D�faire"
229 "Refaire"
230 "Requ�te"
231 "Effacer tout"

$   Messages 232-242 relate to operators available in a query
$ expression, and appear in the Query Editor on option menu buttons.

$       232 "Matches" means the entry in the adjacent entry field will
$           be compared exactly to find a search index database entry.
232 "Correspond"
233 "Ne correspond pas"
234 "Commence par"
235 "Ne commence pas par"
$	236	Boolean operator OR
236 "Ou"
$	237	"Xor" is for Boolean logic "Exclusive OR"
237 "Xor"
$	238	Boolean operator AND
238 "Et"
239 "Pr�s"
240 "Avant"
241 "Importance"
242 "Proximit�"
243 "Etendue"
244 "Oui"
245 "Non"
246 "Correspondances"
247 "G�n�ralit�s"
248 "t"
249 "T�ches"
250 "T"
251 "R�f�rence"
252 "R"
253 "Utiliser l'aide"
254 "U"
255 "A propos du Gestionnaire des informations"
256 "i"
257 "G�n�ralit�s"
258 "G"
259 "o"
260 "Historique"
261 "Liste de l'historique"
262 "La section n'est plus disponible."
263 "Cliquez sur un graphique pour le d�tacher."
264 "Elever le graphique"
265 "Attacher le graphique"



$       270  "..." is a button label indicating a list from which an
$            entry may be selected to fill a preceeding text field.
$            In this case, the user may enter a path into a text field
$            or activate the button with "..." to be presented with
$            a File Selection Box. The object is to select an Infolib
$            path.
270 "..."



$set	8
$ 
$ dtinfo quick help messages (to be exhibited on status display area)
$ 
1 "Vers la section pr�c�dente de l'historique"
2 "Vers la section suivante de l'historique"
3 "Vers la section pr�c�dente du document"
4 "Vers la section suivante du document"

$ A search "match" is the same as a search "hit". "Match" is more
$ descriptive.
5 "Vers la correspondance pr�c�dente"
6 "Vers la correspondance suivante"

7 "Imprimer la section en cours"
8 "Afficher la liste des livres"
9 "Afficher la carte graphique"
10 "Ancrer (d�tacher) cette fen�tre pour emp�cher (permettre) l'utilisation de nouveaux documents."
11 "Sp�cifier l'�tendue de recherche � l'aide de l'Editeur d'�tendue"
52 "Afficher la section s�lectionn�e"
53 " Afficher la section s�lectionn�e dans une liste de livres s�par�e"
54 "Imprimer la section s�lectionn�e"
55 "Ouvrir une biblioth�que d'informations suppl�mentaire"
56 "Fermer la biblioth�que d'informations s�lectionn�e"
57 "Effectuer une recherche � l'aide de l'Editeur de requ�tes"
58 "Afficher la liste des signets et des notes"
60 "Sp�cifier l'�tendue de recherche"
62 " Sp�cifier l'�tendue de  recherche � l'aide de l'Editeur d'�tendue"
64 "Rechercher %s"


$set	9
$ 
$ messages specific to bookmark edit dialog
$ 
1 "Dtinfo: Editeur de signets"
2 "La mise � jour des signets a �chou�."


$set	10
$ 
$ messages specific to detached graphic window
$ 
1 "Dtinfo: Graphique d�tach�"
2 "Graphique d�tach�"
3 "Illustration raster (non-redimensionable)"
4 "Illustration vecteur (redimensionable)"
5 "Mise � l'�chelle de l'illustration, patientez s'il vous pla�t..."
$ 
$ Dtinfo*SetZoom
$ 
6 "Entrer le nouveau pourcentage de l'�chelle:"
$ 
$ Dtinfo*SetZoomTitle
$ 
7 "Dtinfo: D�finir l'�chelle"
$ 
8 "Dtinfo: "
9 "Illustration raster (redimensionable)"


$set	11
$ 
$ messages specific to mark list window
$ 

$	1 is the title of a window containing a list of the
$ user's bookmarks
1 "Dtinfo: Liste des signets de l'utilisateur"


$set	12
$ 
$ messages specific to mark selection dialog
$ 
$   Messages 1 & 2: "Select" and "Edit" are verbs
1 "Dtinfo: S�lectionner le signet"
2 "Dtinfo: Modifier le signet"


$set	13
$ 
$ messages specific to section history window
$ 
1 "Dtinfo: Historique de la section"


$set	14
$ 
$ messages specific to preferences window
$ 
1 "Dtinfo: Pr�f�rences"
2 "Dtinfo: Obtenir la g�om�trie"


$set	15
$ 
$ messages specific to printing
$ 
1 "Dtinfo: Imprimer"
$          Messages 2 - 5 are obsolete, and have been replaced by 12
2 Impossible de trouver un Gestionnaire de bo�te de dialogue d'impression dans l'environement
3 Impossible de lancer le Gestionnaire de bo�tes de dialogue d'impression
4 Le Gestionnaire de bo�te de dialogue d'impression n'est pas autoris� � se connecter � l'�cran vid�o
5 Le Gestionnaire de bo�te de dialogue d'impression n'est pas autoris� � se connecter � l'�cran d'impression
6 Impossible d'afficher le Gestionnaire de bo�te de dialogue d'impression
7 Impossible de copier les donn�es d'impression par d�faut
8 Erreur d'impression au fichier
9 T�che d'impression en cours 
10 Dtinfo: �tat de l'impression
11 Le travail d'impression a �chou�.\n\nLe serveur d'impression X manque temporairement de ressources.
$       Message 12 is used to handle errors from the PDM
12	Erreur du Gestionnaire d'impression (PDM) - configuration a �chou�.

$set	16
$ 
$ messages specofic to search scope editor window
$ 
$	1	Edit the Scope for for use in a Search
1 "Dtinfo: Editeur d'�tendue de recherche"
$ 
$ Dtinfo*SaveScope
$ 
2 "Tapez le nom de la nouvelle �tendue:"
$ 
$ Dtinfo*SaveScopeTitle
$ 
3 "Dtinfo: Enregistrer l'�tendue"
4 "Toutes les biblinfos"


$set	17
$ 
$ messages specific to search result window
$ 
$	1	"Search Results" is for the results of a search
1 "Dtinfo: R�sultats de la recherche"


$set	18
$ 
$ messages specific to open locator dialog, and locator
$ input formats in general.
$ 
$ 1	"Dtinfo: Open Locator"
1 "Dtinfo: Ouvrir le point d'implantation"

$ 2     "Locator specification format error."
2 "Erreur du format de sp�cification du point d'implantation."

$ 3     "Locator resolution failed."
3 "La r�solution du point d'implantation a �chou�."

$ 4     "Locator resolution failed within the loaded infolibs."
4 " La r�solution du point d'implantation a �chou� dans les biblinfos charg�es."

$ 5     "Document not found."
5 "Document introuvable."

$ 6     "No locator value provided."
6 "Aucune valeur fournie pour le point d'implantation"


$set	19
$ 
$ messages specific to query editor window
$ 
1 "Dtinfo: Editeur de requ�tes"


$set	20
$ 
$ dtinfo general messages
$ 
$ 
$ Dtinfo*PixmapAllocationError
$ 
1 "Pas assez de m�moire de serveur disponible\n\
pour reproduire ce graphique."
$ 
$ Dtinfo*AbandonChanges
$ 
2 "Abandonner les modifications ?"
$ 
$ Dtinfo*NoHelp
$ 
3 "Impossible de trouver l'information d'aide."
$ 
$ Dtinfo*NoSelection
$ 
4 "Pas de texte s�lectionn�.\n\
S�lectionnez-le puis essayez � nouveau."
$ 
$ Dtinfo*AbandonBookmarks
$ 
5 "Des signets ouverts ne sont pas enregistr�s.\n\
Quitter sans les enregistrer ?"
$ 
$ Dtinfo*ConfirmQuit
$ 
6 "Quitter Dtinfo?"
$ 
$ Dtinfo*BadTocHierarchy
$ 
7 "Enregistrer une erreur"
$ 
$ Dtinfo*LinkToBookTitle
$ 
8 "Lier � %s: %s"
$ 
$ Dtinfo*LinkToTitle
$ 
9 "Lier � %s"
$ 
$ Dtinfo*MarkCreateFailed
$ 
10 "Dtinfo ne peut pas cr�er ce signet."
$ 
$ Dtinfo*MarkDeleteFailed
$ 
11 "Dtinfo ne peut pas supprimer ce signet."
$ 
$ Dtinfo*MarkMoveFailed
$ 
12 "Dtinfo ne peut pas d�placer ce signet."
$ 
$ Dtinfo*MaxDepthExceeded
$ 
13 "Enregistrer une erreur"
$ 
$ Dtinfo*MarkIconInvisible
$ 
14 "Impossible d'afficher le signet s�lectionn�.\n\
Il est hors de la r�gion de visualisation de cette section."
$ 
$ Dtinfo*MViewNoBase
$ 
15 "Impossible d'acc�der au signet\n\
s�lectionn�.\n\
Chargez la Biblinfo correcte."
$ 
$ Dtinfo*GetGeometry
$ 
16 "Cliquez dans la fen�tre Dtinfo dont la taille \n\
doit �tre sauvegard�e par d�faut."
$ 
$ Dtinfo*SaveModifiedScope
$ 
17 "Sauvegarder les modifications de l'�tendue en cours ?"
$ 
$ Dtinfo*BadScopeName
$ 
18 "Les caract�res deux points (:), virgule (,),\n\
et point virgule (;) ne sont pas autoris�s\n\
dans le nom de l'�tendue de recherche."
$ 
$ Dtinfo*EmptyScopeName
$ 
19 "Entrez un nom d'�tendue correct."
$ 
$ Dtinfo*ScopeNameTooLong
$ 
20 "Le nom de l'�tendue de recherche ne peut pas exc�der 30 caract�res.\n\
Entrez un nom plus court."
$ 
$ Dtinfo*DuplicateScopeName
$ 
21 "Le nom entr� est d�j� utilis�.\n\
Entrez un nom unique."
$ 
$ Dtinfo*Everything
$	22	"Everything" refers to section components like
$		titles, body, and related.
$ 
22 "Tout"
$ 
$ Dtinfo*Titles
$ 
23 "Titres"
$ 
$ Dtinfo*Body
$	24	"Body" as in the body of text.
$ 
24 "Corps"
$ 
$ Dtinfo*Examples
$ 
25 "Exemples"
$ 
$ Dtinfo*Index
$ 
26 "Index"
$ 
$ Dtinfo*Tables
$ 
27 "Tables"
$ 
$ Dtinfo*Graphics
$ 
28 "Graphiques"
$ 
$ Dtinfo*ScopeDeleteConfirm
$ 
29 "Supprimer l'�tendue affich�e?"
$ 
$ Dtinfo*CurrentSection
$ 
30 "Section en cours"
$ 
$ Dtinfo*IgnoredScopes
$ 
31 "Les �tendues sauvegard�es incorrectes \n\
pour ces biblinfos sont ignor�es."
$ 
$ Dtinfo*MarkBaseOpenFailed
$ 
32 "Impossible d'ouvrir la base de donn�es de signets de l'utilisateur."
$ 
$ Dtinfo*NoOpenMarkBases
$ 
33 "La base de donn�es de signets de l'utilisateur introuvable.\n\
Dtinfo ne peut pas cr�er un signet."
$ 
$ Dtinfo*MarkBaseReadOnly
$ 
34 "Autorisation en lecture seulement pour la base de donn�es de signets en cours."
$ 
35 "Erreur inconnue dans le document: contactez votre support technique."

36 "Le moteur de recherche (dans UAS_SearchEngine) a envoy� \n\
un message inattendu:\n\
Contactez votre support technique."
$ 
$ Dtinfo*TooManyIbases
$ 
37 "Vous ne pouvez rechercher que les premiers rayons %d\n\
de l'�tendue en cours � cause de la limite du moteur de recherche.\n\
Continuer ?"
$ 
$ Dtinfo*DemoFailure
$ 
38 "C'est une version d�valuation de l'Explorateur.\n\
Pas d'autorisation d'acc�s � cette Biblinfo."
$ 
$ Dtinfo*StyleSheetSyntaxError
$ 
39 "Une erreur s'est produite dans la feuille de style de ce document.\n\
Les fonctions par d�faut ont �t� appliqu�es."
$ 
$ Dtinfo*NoHits
$ 
40 "Correspondances introuvables pour cette requ�te."
$ 
$ Dtinfo*BadQuery
$ 
41 "Dtinfo ne comprend pas la requ�te.\n\
Entrez-en une correcte."
$ 
$ Dtinfo*SearchError
$ 
42 "Une erreur interne du moteur de recherche s'est produite. Toute\n\
recherche ult�rieure de cette session de l'Explorateur �chouera.\n\n\
Ce probl�me a �t� enregistr� et sera r�solu dans la prochaine version du \n\
produit. Une solution temporaire consiste � �viter les requ�tes qui provoquent\n\
ce probl�me. Pour re initialiser la recherche,\n\
quittez l'Explorateur puis re-lancez-le."
$ 
$ Dtinfo*KernelError
$ 
43 " Une erreur interne du moteur de recherche s'est produite.\n\
Il est probable que le r�pertoire /usr/tmp \n\
se trouve sur un tmpfs filesystem (ou lui est connect�). Toute\n\
recherche ult�rieure de cette session de l'Explorateur �chouera.\n\n\
Ce probl�me a �t� enregistr�. Une solution temporaire consiste � \n\
reconfigurer le r�pertoire /usr/tmp de fa�on qu'il ne soit pas sur\n\
le tmpfs filesystem (ou qu'il ne lui soit pas connect�).\n\
Ensuite, relancez l'Explorateur pour re-initialiser la recherche \n\
qui devrait alors fonctionner correctement. Pour de plus amples d�tails \n\
consultez l'administrateur de syst�me."
$ 
$ Dtinfo*FulcrumNoMemory
$ 
44 "Il est impossible au moteur de recherche de compl�ter la requ�te\n\
parce qu'il manque de m�moire. Avant de poursuivre la recherche,\n\
fermez d'autres applications ou augmentez la m�moire\n\
physique ou virtuelle du syst�me."
$ 
$ Dtinfo*FulcrumError
$ 
45 "Une erreur du moteur de recherche a eu lieu. \n\
Rapportez l'erreur de recherche %d au soutien technique."
$ 
$ Dtinfo*BadHelp
$ 
46 "Ce bouton est connect� � un document Dtinfo qui n'existe pas\n\
dans les Biblinfos courantes charg�es."
$ 
$ Dtinfo*query_is_read_only
$ 
47 "C'est une zone d'affichage seulement. Pour modifier la requ�te,\n\
utilisez l'Editeur de requ�te ou la zone de recherche rapide\n\
dans les fen�tres Lecture ou Liste des livres."
$ 
$ Dtinfo*ExceedRdWindows
$ 
48 "Vous avez d�j� atteint le nombre maximal de fen�tres de lecture (%d)\n\
actives d�fini dans les Pr�f�rences de l'utilisateur."
$ 
$ Dtinfo*NoPrefBase
$ 
49 "Aucune base de donn�es Pr�f�rence de l'utilisateur disponible."
$ 
$ Dtinfo*PrefBaseReadOnly
$ 
50 "La base de donn�es Pr�f�rence de l'utilisateur est ouverte en lecture \n\
seule. Impossible de sauvegarder les nouvelles pr�f�rences."
$ 
$ Dtinfo*DeadEndLink
$ 
51 "Le document ou la section demand�s ne sont pas disponibles."
$ 
$ Dtinfo*MarkPositionFailed
$ 
52 "Dtinfo ne peut pas afficher le signet\n\
\42%s\42\n\
parce que le paragraphe auquel il est associ� \n\
n'existe plus."
$ 
$ Dtinfo*ScopeChangeAbandon
$ 
53 "Abandonner les modifications de l'�tendue en cours ?"
$ 
$ Dtinfo*InformationLibrary
$ 
63 "Biblioth�que d'Informations"
$ 
$ Dtinfo*en fonction
$ 
64 "On"
$ 
$ Dtinfo*hors fonction
$ 
65 "Hors fonction"
$ 
67 "Impossible de cr�er la Biblinfo."

68 "La cr�ation de la Biblinfo a �chou�."
$ 
69 "L'�valuation des r�sultats de la recherche ne sont pas disponibles."

$	70	The "qualified locator" is a "fully qualified
$		locator" as opposed to the simple format.
70 "M�thode d'acc�s incorrecte dans le point d'implantation qualified  (URL)."

71 "la cr�ation du document a �chou�."

72 "Dtinfo: D�tacher le graphique"
73 "Cliquez sur un graphique pour le d�tacher."


$set	21
$ 
$ messages specific to message dialogs
$ 

$ Dtinfo*ErrorDialogTitle
$ 
1 "Dtinfo: Erreur"

$ Dtinfo*WarningDialogTitle
$ 
2 "Dtinfo: Avertissement"

$ Dtinfo*InfoDialogTitle
$ 
3 "Dtinfo: Information"

$ Dtinfo*ProgressDialogTitle
$ 
$	4	"Progress" is a level of completion in regards
$		 to a task.
4 "Dtinfo: Progression"

$ Dtinfo*QuitDialogTitle
$ 
5 "Dtinfo: Confirmer Quitter"

$ Dtinfo*QuestionDialogTitle
$ 
6 "Dtinfo: Question"
$ 
7 "Dtinfo: Enregistrer une erreur"


$set	22
$ 
$ dtinfo version information
$ 
$ 
$	Dtinfo*Version
$ 
1 "CDE Dtinfo Explorateur\n\
\n\
Copyright (c) 1996 Chisholm Technologies, Inc.,\n\
Austin, TX 78758 USA\n\
\n\
Copyright (c) 1994, 1995 HAL Computer Systems, Inc.\n\
\n\
All Rights Reserved.\n\
\n\
U. S. Government Restricted Rights\n\
Use, duplication or disclosure by the Government is subject\n\
to restrictions set forth in subparagraphs (a) through (d)\n\
of the Commercial Computer - Restricted Rights clause at FAR\n\
52.227-19 when applicable, or in subparagraph (c)(1)(ii) of\n\
the Rights in Technical Data and Computer Software clause at\n\
DFARS 252.227-7013, and in similar clauses in the NASA FAR\n\
Supplement. Contractor/manufacturer is HAL Computer\n\
Systems, 1315 Dell Avenue, Campbell, CA 95008 USA."


$set	23
$ 
$ messages specific to CanvasRenderer (dtinfo I/F to DtCanvas/DtHelp)
$ 


$set	24
$ 
$ messages specific to UAS/Base modules
$ 
1 "Le point d'implantation ne fournit aucun acc�s (URL)."
2 "Impossible de cr�er des objets %s: "

$ In the following, do not translate any part of "UAS_ObjList<T>::operator[]"
$ 
3 "Erreur de plage: UAS_ObjList<T>::operator[]"
4 "Erreur de plage: UAS_PtrList<T>::operator[]"


$set	27
$ 
$ messages specific to UAS/MMDB modules
$ 
1 "Les rayons suivants sont incorrects:"
2 "Chemin infolib MMDB incorrect: %s"
3 "Chemin infolib MMDB incorrect ignor�: %s"
4 "MMDB Biblioth�que%d"
5 "MMDB biblinfo: "
6 "Biblinfo %s"


$set	28
$ 
$ messages specific to graphical map window
$ 
1 "Dtinfo: Carte locale"
2 "Dtinfo: "


$set	29
$ 
$ messages specific to search history window
$ 
$	1	"Search Results History" is a history of the
$ search results already obtained under the dtinfo session, for
$ prior queries.
1 "Dtinfo: Historique des r�sultats de recherche"


$set	30
$ 
$ messages specific to window system module
$ 
1 "Dtinfo: Erreur fatale"
2 "Abandon..."
3 Impossible d'ouvrir l'�cran.\n

$set	31
$ 
$ messages specific to printing
$ 
1 "Some page header "
2 "Some page footer - page %d"


$set	40
$ 
$ messages specific to environmental interface or program context
$ 

$ 1     ""
1 "Pas mis en oeuvre."
2 Argument non valide
3 ERROR: Vous devez sp�cifier l'option -sect avec l'option -print.
4 Utilisation: dtinfo...
5 Cette application supporte toutes les options de lignes de commande X Toolkit standard.


$set	41
$ The messages in this set will only appear in the users
$   "errorlog" file.
$ 
$ ******************************************************************************
$ 
$ messages specific to tooltalk interface and operations.
$ Note that many errors defined by tooltalk are passed through
$ and therefore not repeated here.
$ 

$ 1     "Can't get tt session for X display %s"
1 Impossible d'obtenir la session tt session pour l'�cran X:\n%s

$ 2     "Could not set default tooltalk session."
2 Impossible de d�finir la session tooltalk:\n%s

$ 3 Failed to open ToolTalk connection.
3 L'ouverure de la connexion ToolTalk a �chou�:\n%s

$ 4     "Could not declare ptype DtInfo."
4 Impossible de d�clarer ptype DtInfo:\n%s

$ Messages 5-10: These messages result from an error in a tt_* function
$    call.
$ 
5 Le processus de la session tt (1) n'est pas en cours d'ex�cution \n\
et le service ToolTalk ne peut pas le relancer.
6 L'identificateur du processus par d�faut est incorrect ou p�rim�.
7 La session sp�cifi�e ToolTalk est p�rim�e ou incorrecte.

$ 
$ Message 8: Do not localize the word DtInfo.
$ 
8 Aucun type de processus install� \n\
ne s'appelle 'DtInfo'.

$ 
$ Message 9: Do not localize the word DtInfoPrint.
$ 
9 Aucun type de processus install� \n\
ne s'appelle 'DtInfo'.


10 Le num�ro de l'erreur est inconnu.

$set	42
$ 
$ messages specific to UAS/DtSR_SearchEngine modules
$ 
1 "DtSearch ne supporte pas la requ�te."
