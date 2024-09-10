#include <stdio.h>
#include <string.h>

int main()
{
    int choix;
    char T1[100][100], T2[100][100], T6[100][100];
    int T3[100], T4[100], T5[100];
    int totaltach = 0;
    int timeout = 0;

    int A, R;

    while (1)
    {
        printf("\n\n");
        printf("_____________________________\n");
        printf("|   Gestion de Taches ToDo   |\n");
        printf("|1-Ajouter une tach          |\n");
        printf("|2-Ajouter plusieurs taches. |\n");
        printf("|3-Afficher les taches       |\n");
        printf("|4-Supprimer une tache       |\n");
        printf("|5-Modifier une tache        |\n");
        printf("|6-Rechercher les Taches     |\n");
        printf("|7-Statistiques              |\n");
        printf("|8-Mise a jour du temps      |\n");
        printf("|^_(quand tu a une erreur)   |\n");
        printf("|9-Quitter                   |\n");
        printf("|____________________________|\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        getchar();

        int anne = 2024, jour = 10, mois = 9;

        switch (choix)
        {
        case 1:
            printf("\n\n________________________________________________________");
            printf("\nAjouter une tache");
            for (int i = totaltach; i < totaltach + 1; i++)
            {

                printf("\nidentifiant du tach est: %d", i + 1);
                printf("\nle titre du tach: ");
                scanf("%[^\n]", &T1[i]);
                getchar();
                printf("la description du tach: ");
                scanf("%[^\n]", &T2[i]);
                getchar();
                printf("la deadline du tach: \n");
                printf("\t\tentre l'annee: ");
                scanf("%d", &T3[i]);
                getchar();

                printf("\t\tentre le mois: ");
                scanf("%d", &T4[i]);
                getchar();

                printf("\t\tentre le jour: ");
                scanf("%d", &T5[i]);
                getchar();

                printf("le statut du tach: ");
                scanf("%[^\n]", &T6[i]);
                getchar();

                if (anne > 2024)
                {
                    printf("année invalide\n");
                    return 0;
                }

                if (anne == T3[i])
                {
                    if (mois > 12)
                    {
                        printf("mois invalide\n");
                        return 0;
                    }
                    if (mois == T4[i])
                    {
                        if (jour > 31)
                        {
                            printf("jour invalide\n");
                            return 0;
                        }
                        if (jour == T5[i])
                        {
                            timeout++;
                        }
                    }
                    else if (mois < T4[i])
                    {
                        timeout++;
                    }
                }
                else if (anne < T3[i])
                {
                    timeout++;
                }
            }

            totaltach++;

            break;

        case 2:
            int nbTach;
            printf("\n\n________________________________________________________");
            printf("\nCombien de liste de taches voulez-vous ajouter ? ");
            scanf("%d", &nbTach);
            getchar();
            int qu = totaltach;

            for (int i = 0; i < nbTach; i++)
            {
                for (int i = totaltach; i < totaltach + 1; i++)
                {

                    printf("\nidentifiant du tach est: %d", i + 1);
                    printf("\nle titre du tach: ");
                    scanf("%[^\n]", &T1[i]);
                    getchar();
                    printf("la description du tach: ");
                    scanf("%[^\n]", &T2[i]);
                    getchar();
                    printf("la deadline du tach: \n");
                    printf("\t\tentre l'annee: ");
                    scanf("%d", &T3[i]);
                    getchar();

                    printf("\t\tentre le mois: ");
                    scanf("%d", &T4[i]);
                    getchar();

                    printf("\t\tentre le jour: ");
                    scanf("%d", &T5[i]);
                    getchar();

                    printf("le statut du tach: ");
                    scanf("%[^\n]", &T6[i]);
                    getchar();

                    if (anne > 2024)
                    {
                        printf("année invalide\n");
                        return 0;
                    }

                    if (anne == T3[i])
                    {
                        if (mois > 12)
                        {
                            printf("mois invalide\n");
                            return 0;
                        }
                        if (mois == T4[i])
                        {
                            if (jour > 31)
                            {
                                printf("jour invalide\n");
                                return 0;
                            }
                            if (jour == T5[i])
                            {
                                timeout++;
                            }
                        }
                        else if (mois < T4[i])
                        {
                            timeout++;
                        }
                    }
                    else if (anne < T3[i])
                    {
                        timeout++;
                    }
                }

                totaltach++;
            }
            break;

        case 3:
            printf("\n\n________________________________________________________\n");
            printf("Afficher tous les taches\n");
            printf("1-Afficher sans trie\n");
            printf("2-Afficher par ordre alphabetique\n");
            printf("3-Afficher par deadline\n");
            printf("4-Afficher les taches on 3 jours ou moins\n");
            printf("_______________________________________________________\n");
            printf("Choisissez une option : ");
            scanf("%d", &R);
            getchar();

            switch (R)
            {
            case 1:
                for (int i = 0; i < totaltach; i++)
                {

                    printf("________________________________________________________\n");
                    printf("|identifiant du tach est: %d\n", i + 1);
                    printf("|le titre du tach: %s\n", T1[i]);
                    printf("|la description du tach: %s\n", T2[i]);
                    printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                    printf("|le statut du tach: %s\n", T6[i]);
                    printf("________________________________________________________\n\n");
                }
                break;

            case 2:
                for (int i = 0; i < totaltach; i++)
                {
                    for (int j = i + 1; j < totaltach; j++)
                    {
                        if (strcmp(T1[i], T1[j]) > 0)
                        {
                            char temp1[100];
                            char temp2[100];
                            int temp3, temp4, temp5;
                            char temp6[100];

                            strcpy(temp1, T1[i]);
                            strcpy(temp2, T2[i]);
                            temp3 = T3[i];
                            temp4 = T4[i];
                            temp5 = T5[i];
                            strcpy(temp6, T6[i]);

                            strcpy(T1[i], T1[j]);
                            strcpy(T2[i], T2[j]);
                            T3[i] = T3[j];
                            T4[i] = T4[j];
                            T5[i] = T5[j];
                            strcpy(T6[i], T6[j]);

                            strcpy(T1[j], temp1);
                            strcpy(T2[j], temp2);
                            T3[j] = temp3;
                            T4[j] = temp4;
                            T5[j] = temp5;
                            strcpy(T6[j], temp6);
                        }
                    }
                }
                for (int i = 0; i < totaltach; i++)
                {
                    printf("________________________________________________________\n");
                    printf("|identifiant du tach est: %d\n", i + 1);
                    printf("|le titre du tach: %s\n", T1[i]);
                    printf("|la description du tach: %s\n", T2[i]);
                    printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                    printf("|le statut du tach: %s\n", T6[i]);
                    printf("________________________________________________________\n\n");
                }
                break;

            case 3:
                int d, m, y;
                printf("Entre la date pour afficher les taches par deadline: \n");
                printf("\t\tentre le jour: ");
                scanf("%d", &d);
                printf("\t\tentre le mois: ");
                scanf("%d", &m);
                printf("\t\tentre l'annee: ");
                scanf("%d", &y);
                printf("\n");
                for (int i = 0; i < totaltach; i++)
                {
                    if (T3[i] == y && T4[i] == m && T5[i] == d)
                    {
                        printf("________________________________________________________\n");
                        printf("|identifiant du tach est: %d\n", i + 1);
                        printf("|le titre du tach: %s\n", T1[i]);
                        printf("|la description du tach: %s\n", T2[i]);
                        printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                        printf("|le statut du tach: %s\n", T6[i]);
                        printf("________________________________________________________\n\n");
                    }
                }
                break;

            case 4:
                int today[3] = {jour, mois, anne};
                for (int i = 0; i < totaltach; i++)
                {
                    int deadline[3] = {T5[i], T4[i], T3[i]};
                    int diff[3] = {deadline[0] - today[0], deadline[1] - today[1], deadline[2] - today[2]};
                    int days = diff[0] + (diff[1] * 30) + (diff[2] * 365);
                    if (days <= 3)
                    {
                        printf("________________________________________________________\n");
                        printf("|identifiant du tach est: %d\n", i + 1);
                        printf("|le titre du tach: %s\n", T1[i]);
                        printf("|la description du tach: %s\n", T2[i]);
                        printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                        printf("|le statut du tach: %s\n", T6[i]);
                        printf("________________________________________________________\n\n");
                    }
                }
                break;

            default:
                printf("Option invalide\n");
                break;
            }

            break;

        case 4:
            if (totaltach == 0)
            {
                printf("\n\n________________________________________________________\n");
                printf("==> Aucune tache a supprimer\n");
                printf("________________________________________________________\n");
            }
            else
            {
                int idToDelete;
                printf("\n\n________________________________________________________\n");
                printf("Supprimer une tache\n");
                printf("Liste des taches:\n");
                for (int i = 0; i < totaltach; i++)
                {
                    printf("Identifiant du tache: %d\n", i + 1);
                    printf("Titre: %s\n", T1[i]);
                    printf("Description: %s\n", T2[i]);
                    printf("Deadline: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                    printf("Statut: %s\n", T6[i]);
                    printf("________________________________________________________\n");
                }
                printf("Entre l'identifiant de la tache a supprimer: ");
                scanf("%d", &idToDelete);
                getchar();

                idToDelete--;

                if (idToDelete < 0 || idToDelete >= totaltach)
                {
                    printf("\n\n________________________________________________________\n");
                    printf("==> Identifiant invalide\n");
                    printf("________________________________________________________\n");
                }
                else
                {

                    for (int i = idToDelete; i < totaltach - 1; i++)
                    {
                        strcpy(T1[i], T1[i + 1]);
                        strcpy(T2[i], T2[i + 1]);
                        T3[i] = T3[i + 1];
                        T4[i] = T4[i + 1];
                        T5[i] = T5[i + 1];
                        strcpy(T6[i], T6[i + 1]);
                    }

                    totaltach--;
                    printf("\n\n________________________________________________________\n");
                    printf("La tache %d a ete supprimee\n", idToDelete + 1);
                    printf("________________________________________________________\n");
                }
            }
            break;

        case 5:
            int modif;
            printf("\n\n________________________________________________________\n");
            printf("Modifier une tache\n");
            printf("1-Modifier la description d'une tache\n");
            printf("2-Modifier le statut du tache\n");
            printf("3-Modifier la deadline d'une tache\n");
            printf("4-Aucune\n");
            printf("________________________________________________________\n");
            printf("Choisissez une option : ");
            scanf("%d", &modif);

            if (totaltach == 0)
            {
                printf("\n\n________________________________________________________\n");
                printf("==> Aucune tache a modifier");
                printf("\n________________________________________________________\n");
            }
            else if (totaltach > 0)
            {
                switch (modif)
                {
                case 1:
                    printf("\n\n________________________________________________________\n");
                    printf("Modifier la description d'une tache\n");
                    for (int i = 0; i < totaltach; i++)
                    {
                        printf("Entre l'identifiant de la tache a modifier: ");
                        scanf("%d", &modif);
                        getchar();
                        printf("la nouvelle description du tach: ");
                        scanf("%[^\n]", &T2);
                        getchar();
                    }
                    printf("________________________________________________________\n");

                    break;
                case 2:

                    printf("\n\n________________________________________________________\n");
                    printf("Modifier le statut du tache\n");
                    for (int i = 0; i < totaltach; i++)
                    {
                        printf("Entre l'identifiant de la tache a modifier: ");
                        scanf("%d", &modif);
                        getchar();
                        printf("la nouvelle Statut du tach: ");
                        scanf("%[^\n]", &T6);
                        getchar();
                    }
                    printf("________________________________________________________\n");

                    break;
                case 3:

                    printf("\n\n________________________________________________________\n");
                    printf("Modifier la deadline d'une tache\n");
                    for (int i = 0; i < totaltach; i++)
                    {
                        printf("Entre l'identifiant de la tache a modifier: ");
                        scanf("%d", &modif);
                        getchar();
                        printf("la nouvelle deadline du tach: ");
                        printf("\t\tentre l'annee: ");
                        scanf("%[^\n]", &T3);
                        getchar();
                        printf("\t\tentre le mois: ");
                        scanf("%[^\n]", &T4);
                        getchar();
                        printf("\t\tentre le jour: ");
                        scanf("%[^\n]", &T5);
                        getchar();
                    }
                    printf("________________________________________________________\n");

                    break;
                case 4:
                    return 0;
                default:
                    printf("\n\n________________________________________________________\n");
                    printf("choix invalide");
                    printf("\n________________________________________________________\n");
                    break;
                }

                break;
            }

        case 6:
            int co, rech;
            printf("\n\n________________________________________________________\n");
            printf("Rechercher une tache\n");
            printf("1-Rechercher une tache par son identifiant\n");
            printf("2-Rechercher une tache par son titre\n");
            printf("3-Aucune\n");
            printf("________________________________________________________\n");
            printf("Choisissez une option : ");
            scanf("%d", &co);
            getchar();

            if (totaltach == 0)
            {
                printf("\n\n________________________________________________________\n");
                printf("==> Aucune tache a modifier");
                printf("\n________________________________________________________\n");
            }
            else if (totaltach > 0)
            {
                switch (co)
                {
                case 1:
                    printf("Entre l'identifiant de la tache a Rechercher: ");
                    scanf("%d", &rech);
                    for (int i = 0; i < totaltach; i++)
                    {
                        if (i + 1 == rech)
                        {
                            printf("________________________________________________________\n");
                            printf("|identifiant du tach est: %d\n", i + 1);
                            printf("|le titre du tach: %s\n", T1[i]);
                            printf("|la description du tach: %s\n", T2[i]);
                            printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                            printf("|le statut du tach: %s\n", T6[i]);
                            printf("________________________________________________________\n\n");
                            break;
                        }
                    }
                    if (rech > totaltach || rech < 1)
                    {
                        printf("\n\n________________________________________________________\n");
                        printf("==> Identifiant invalide\n");
                        printf("________________________________________________________\n");
                    }

                    break;

                case 2:
                    char titre[100];
                    printf("Entre le titre de la tache a Rechercher: ");
                    scanf("%[^\n]", &titre);
                    getchar();
                    int trouver = 0;
                    for (int i = 0; i < totaltach; i++)
                    {
                        if (strcmp(T1[i], titre) == 0)
                        {
                            printf("________________________________________________________\n");
                            printf("|identifiant du tach est: %d\n", i + 1);
                            printf("|le titre du tach: %s\n", T1[i]);
                            printf("|la description du tach: %s\n", T2[i]);
                            printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                            printf("|le statut du tach: %s\n", T6[i]);
                            printf("________________________________________________________\n\n");
                            trouver = 1;
                            printf("________________________________________________________\n");
                            printf("|identifiant du tach est: %d\n", i + 1);
                            printf("|le titre du tach: %s\n", T1[i]);
                            printf("|la description du tach: %s\n", T2[i]);
                            printf("|la deadline du tach: %d/%d/%d\n", T5[i], T4[i], T3[i]);
                            printf("|le statut du tach: %s\n", T6[i]);
                            printf("________________________________________________________\n\n");
                        }
                    }
                    if (!trouver)
                    {
                        printf("\n\n________________________________________________________\n");
                        printf("==> Titre invalide\n");
                        printf("________________________________________________________\n");
                    }
                    break;

                case 3:
                    printf("\n\n________________________________________________________\n");
                    printf("Aucune tache a modifier");
                    printf("\n________________________________________________________\n");
                    break;
                default:
                    printf("\n\n________________________________________________________\n");
                    printf("==> choix invalide");
                    printf("\n________________________________________________________\n");
                    break;
                }
            }

        case 7:
            A = totaltach - timeout;
            printf("\n\n________________________________________________________\n");
            printf("Les statistiques\n");
            printf("Nombre total de taches: %d\n", totaltach);
            printf("Nombre de taches en cours: %d\n", A);
            printf("Nombre de taches finisées: %d\n", timeout);
            printf("________________________________________________________\n");
            break;

        case 8:
            printf("\n\n________________________________________________________\n");
            printf("Entre la annee: ");
            scanf("%[^\n]", &anne);
            getchar();
            printf("Entre le mois: ");
            scanf("%[^\n]", &mois);
            getchar();
            printf("Entre le jour: ");
            scanf("%[^\n]", &jour);
            getchar();
            printf("________________________________________________________\n");
            timeout = 0;
            break;

        case 9:
            printf("\n\n________________________________________________________\n");
            printf("Aurevoir");
            printf("\n________________________________________________________\n");
            return 0;
            break;

        default:
            printf("\n\n________________________________________________________\n");
            printf("==> choix invalide");
            printf("\n________________________________________________________\n");
            break;
        }
    }
}
