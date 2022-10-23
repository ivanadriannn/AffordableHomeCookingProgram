#include <stdio.h>
#include <string.h>
struct ingredients
{
    char name[105] = {'\0'};
    double amount = 0;
    char type[15] = {'\0'};
    double price = 0;
} currentIngredients;

struct budget
{
    long long int budget, allowance;
    int days;
} currentBudget;

struct recipes
{
    char recipe[200] = {'\0'};
    double total = 0;
    struct ingredients list[30];
    unsigned int count = 0;
} currentRecipes;

char menuFunction[10], garbageInputs[255];
short menuPrint = 1;
int menuMain();
int menuIngredientList();
int menuRecipes();
int menuBudgetPlanner();
int menuAddingIngredients();
int menuAddingBudget(short condition);
int menuRemovingIngredients();
int menuAddingRecipe();
int menuViewingRecipe(struct recipes *permList2, int s);
int menuRemovingRecipes(struct recipes *permList2, int s);
long long int menuCooking(struct budget currentBudget);

int addingIngredients();
int addingRecipes();
int addingBudget(short condition);
int removingIngredients();
int removingRecipes(struct recipes *permList2, int s);

int sortIngredients(struct ingredients *example, int size);
void merge_sort(struct ingredients *, int length);
void merge_sort_recursion(struct ingredients *, int l, int r);
void merge_sorted_arrays(struct ingredients *, int l, int m, int r);
int z(struct ingredients *temp_left, struct ingredients *temp_right, int i, int j);

int sortRecipes(struct recipes *example, int size);
void merge_sort2(struct recipes *a, int length);
void merge_sort_recursion2(struct recipes *a, int l, int r);
void merge_sorted_arrays2(struct recipes *a, int l, int m, int r);
int z2(struct recipes *temp_left, struct recipes *temp_right, int i, int j);

int searchIngredients(struct ingredients *a, struct recipes e, int l, int r, int p);
int searchRecipes(struct recipes *a, char *tempRecipeName, int l, int r);

int main()
{
    menuMain();
    (menuPrint)?printf("\nCode executed successfully"):printf("\nSomething went wrong");
}

int menuIngredientList()
{
    if (menuPrint)
    {

        FILE *fp;
        char UI;
        fp = fopen("menu/menuIngredientList.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    if (menuPrint)
    {
        FILE *fp2;
        fp2 = fopen("data/dataIngredientList.txt", "r");
        if (fp2 == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            int x = 0;
            fscanf(fp2, "%d", &x);
            struct ingredients tempList[x];
            printf("\nYour ingredients:\n\n");
            for (int y = 0; y < x; y++)
            {
                fscanf(fp2, "%s %lf %s %lf", tempList[y].name, &tempList[y].amount, tempList[y].type, &tempList[y].price);
                printf(" %d. %s\n Rp%.0lf/%.0lf%s\n\n", y + 1, tempList[y].name, tempList[y].price, tempList[y].amount, tempList[y].type);
            }
            printf("=============================================================================\n\n");
        }
        fclose(fp2);
    }
    scanf("%[^\n]s", menuFunction);
    getchar();
    if (strcmp(menuFunction, "1") == 0)
    {
        menuPrint = 1;
        printf("We are in menu ingredients");
    }
    else if (strcmp(menuFunction, "add") == 0)
    {
        menuPrint = 1;
        menuAddingIngredients();
    }
    else if (strcmp(menuFunction, "delete") == 0)
    {
        menuPrint = 1;
        menuRemovingIngredients();
    }
    else if (strcmp(menuFunction, "back") == 0)
    {
        menuPrint = 1;
        menuMain();
    }
    else if (strcmp(menuFunction, "end") == 0)
    {
        return 0;
    }
    else
    {
        menuPrint = 0;
        printf("Please enter a valid input.\n");
        menuIngredientList();
    }
}
int menuAddingIngredients()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuAddingIngredients.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    addingIngredients();
    menuIngredientList();
}

int addingIngredients()
{
    FILE *tempFile;
    tempFile = tmpfile();
    if (tempFile == 0)
    {
        printf("Unable to create tempFile.\n");
    }
    else
    {
        int test2 = 1, p = 0, q = 0, s, totalList = 0;
        do
        {
            p++;
            struct ingredients tempIngredients;
            char tempString[255];
            int i, test = 1, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0;
            double b = 0;
            double d = 0;
            scanf("%[^\n]s", tempString);
            getchar();
            if (strcmp(tempString, "stop") == 0)
            {
                test2 = 0;
            }
            else
            {
                o = strlen(tempString) - 1;
                while (tempString[j] != '_')
                {
                    if (j == o)
                    {
                        test = 0;
                        break;
                    }
                    j++;
                }
                k = j + 1;
                if (test)
                {
                    while (tempString[k] != '_')
                    {
                        if (k == o)
                        {
                            test = 0;
                            break;
                        }
                        k++;
                    }
                }
                l = k + 1;
                if (test)
                {
                    while (tempString[l] != '_')
                    {
                        if (l == o)
                        {
                            test = 0;
                            break;
                        }
                        l++;
                    }
                }
                m = l + 1;
                if (test)
                {
                    while (tempString[m] != '\0')
                    {
                        m++;
                    }
                }
                j--;
                k--;
                l--;
                m--;
                if (j + 1 < 26 && k - j + 1 < 18 && l - k + 1 < 15 && m - l + 1 < 18)
                {
                    for (i = 0; tempString[i] != '_'; i++)
                    {
                        if ((tempString[i] >= 'a' && tempString[i] <= 'z'))
                        {
                            tempIngredients.name[i] = tempString[i];
                        }
                        else
                        {
                            test = 0;
                            break;
                        }
                    }
                    if (test)
                    {
                        for (i = i + 1; tempString[i] != '_'; i++)
                        {
                            if (tempString[i] >= '0' && tempString[i] <= '9')
                            {
                                long long int y = 1;
                                for (int z = 0; z < k - i; z++)
                                {
                                    y *= 10;
                                }
                                tempIngredients.amount += (tempString[i] - '0') * y;
                            }
                            else
                            {
                                test = 0;
                                break;
                            }
                        }
                    }
                    if (test)
                    {
                        for (i = i + 1; tempString[i] != '_'; i++)
                        {
                            if (tempString[i] >= 'a' && tempString[i] <= 'z')
                            {
                                tempIngredients.type[n] = tempString[i];
                                n++;
                            }
                            else
                            {
                                test = 0;
                                break;
                            }
                        }
                    }
                    if (test)
                    {
                        for (i = i + 1; tempString[i] != '\0'; i++)
                        {
                            if (tempString[i] >= '0' && tempString[i] <= '9')
                            {
                                long long int y = 1;
                                for (int z = 0; z < m - i; z++)
                                {
                                    y *= 10;
                                }
                                tempIngredients.price += (tempString[i] - '0') * y;
                            }
                            else
                            {
                                test = 0;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    test = 0;
                }

                if (strcmp(tempIngredients.type, "grams") == 0)
                {
                    tempIngredients.price = 100 / tempIngredients.amount * tempIngredients.price;
                    tempIngredients.amount = 100;
                }
                else if (strcmp(tempIngredients.type, "ounces") == 0)
                {
                    tempIngredients.price = 100 / (tempIngredients.amount * 28.3495) * tempIngredients.price;
                    tempIngredients.amount = 100;
                }
                else if (strcmp(tempIngredients.type, "kilograms") == 0)
                {
                    tempIngredients.price = 100 / (tempIngredients.amount * 1000) * tempIngredients.price;
                    tempIngredients.amount = 100;
                }
                else if (strcmp(tempIngredients.type, "pounds") == 0)
                {
                    tempIngredients.price = 100 / (tempIngredients.amount * 453.592) * tempIngredients.price;
                    tempIngredients.amount = 100;
                }
                else
                {
                    test = 0;
                }
                if (test)
                {
                    fprintf(tempFile, "%s %lf grams %lf\n", tempIngredients.name, tempIngredients.amount, tempIngredients.price);
                }
                else
                {
                    printf("Please enter a valid input\n");
                    p--;
                }
            }
        } while (test2);
        p--;
        if (!test2 && p != 0)
        {
            rewind(tempFile);
            struct ingredients tempList[p];
            for (q; q < p; q++)
            {
                fscanf(tempFile, "%s %lf %s %lf", tempList[q].name, &tempList[q].amount, tempList[q].type, &tempList[q].price);
            }
            fclose(tempFile);
            FILE *fp2;
            fp2 = fopen("data/dataIngredientList.txt", "r");
            if (fp2 == 0)
            {
                printf("Unable to read file.\n");
            }
            else
            {
                fscanf(fp2, "%d", &s);
                totalList += p + s;
                struct ingredients permList[totalList];
                for (int r = 0; r < totalList; r++)
                {
                    if (r < s)
                    {
                        fscanf(fp2, "%s %lf %s %lf", permList[r].name, &permList[r].amount, permList[r].type, &permList[r].price);
                        fgetc(fp2);
                    }
                    else
                    {
                        permList[r] = tempList[r - s];
                    }
                }
                fclose(fp2);
                sortIngredients(permList, totalList);
            }
        }
    }
}

int sortIngredients(struct ingredients *example, int size)
{
    merge_sort(example, size);
    if (menuPrint)
    {
        FILE *fp;
        fp = fopen("data/dataIngredientList.txt", "w");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            fprintf(fp, "%d\n", size);
            for (int x = 0; x < size; x++)
                fprintf(fp, "%s %lf %s %lf\n", example[x].name, example[x].amount, example[x].type, example[x].price);
        }
        fclose(fp);
        return 0;
    }
    else
    {
        printf("please input an original name\n");
        menuPrint = 1;
        addingIngredients();
    }
}

void merge_sort(struct ingredients *a, int length)
{
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(struct ingredients *a, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        merge_sorted_arrays(a, l, m, r);
    }
}

void merge_sorted_arrays(struct ingredients *a, int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    struct ingredients temp_left[left_length];
    struct ingredients temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = a[l + i];

    for (i = 0; i < right_length; i++)
        temp_right[i] = a[m + 1 + i];

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if (i < left_length && (j >= right_length || z(temp_left, temp_right, i, j)))
            a[k] = temp_left[i++];
        else
            a[k] = temp_right[j++];
    }
}

int z(struct ingredients *temp_left, struct ingredients *temp_right, int i, int j)
{
    int k = strcmp(temp_left[i].name, temp_right[j].name);
    if (k == 0)
    {
        menuPrint = 0;
        return 0;
    }
    else if (k == -1)
    {
        return 1;
    }
    else if (k == 1)
    {
        return 0;
    }
}

int menuRemovingIngredients()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuRemovingIngredients.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    removingIngredients();
    menuIngredientList();
}

int removingIngredients()
{
    FILE *fp;
    fp = fopen("data/dataIngredientList.txt", "r");
    if (fp == 0)
    {
        printf("Unable to read file.\n");
    }
    else
    {
        int x = 0, z = 0, garbageCondition = 0;
        fscanf(fp, "%d", &x);
        struct ingredients tempList[x];
        for (int y = 0; y < x; y++)
        {
            fscanf(fp, "%s %lf %s %lf", tempList[y].name, &tempList[y].amount, tempList[y].type, &tempList[y].price);
            fgetc(fp);
        }
        fclose(fp);
        scanf("%d", &z);
        garbageCondition = scanf("%[^\n]s", garbageInputs);
        getchar();

        if (z <= x && z > 0 && garbageCondition == 0)
        {
            FILE *fp2;
            fp2 = fopen("data/dataIngredientList.txt", "w");
            if (fp2 == 0)
            {
                printf("Unable to read file.\n");
            }
            else
            {
                fprintf(fp2, "%d\n", x - 1);

                for (int i = 0; i < x - 1; i++)
                {
                    if (i < z - 1)
                    {
                        fprintf(fp2, "%s %lf %s %lf\n", tempList[i].name, tempList[i].amount, tempList[i].type, tempList[i].price);
                    }
                    else if (i < x - 1)
                    {
                        tempList[i] = tempList[i + 1];
                        fprintf(fp2, "%s %lf %s %lf\n", tempList[i].name, tempList[i].amount, tempList[i].type, tempList[i].price);
                    }
                }
            }
            fclose(fp2);
        }
        else
        {
            printf("please enter a valid input.\n");
            removingIngredients();
        }
    }
}

int menuRecipes()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuRecipes.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    FILE *fp4;
    fp4 = fopen("data/dataRecipeList.txt", "r");
    if (fp4 == 0)
    {
        printf("Unable to read file.\n");
    }
    else
    {
        int s = 0;
        fscanf(fp4, "%d", &s);
        struct recipes permList2[s];
        for (int t = 0; t < s; t++)
        {
            fscanf(fp4, "%s %u", permList2[t].recipe, &permList2[t].count);
            for (int u = 0; u < permList2[t].count; u++)
            {
                fscanf(fp4, "%s %lf %s %lf %lf", permList2[t].list[u].name, &permList2[t].list[u].amount, permList2[t].list[u].type, &permList2[t].list[u].price, &permList2[t].total);
            }
        }
        if (menuPrint)
        {
            for (int u = 0; u < s; u++)
            {
                printf("\n%d. %s Rp%.0lf", u + 1, permList2[u].recipe, permList2[u].total);
            }
            printf("\n\n=============================================================================\n\n");
        }
        fclose(fp4);

        scanf("%[^\n]s", menuFunction);
        getchar();
        if (strcmp(menuFunction, "view") == 0)
        {
            menuPrint = 1;
            menuViewingRecipe(permList2, s);
        }
        else if (strcmp(menuFunction, "delete") == 0)
        {
            menuPrint = 1;
            menuRemovingRecipes(permList2, s);
        }
        else if (strcmp(menuFunction, "add") == 0)
        {
            menuPrint = 1;
            menuAddingRecipe();
        }
        else if (strcmp(menuFunction, "back") == 0)
        {
            menuPrint = 1;
            menuMain();
        }
        else if (strcmp(menuFunction, "end") == 0)
        {
            return 0;
        }
        else
        {
            menuPrint = 0;
            printf("Please enter a valid input.\n");
            menuRecipes();
        }
    }
}

int menuViewingRecipe(struct recipes *permList2, int s)
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuViewingRecipe.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    int z, garbageCondition;
    scanf("%d", &z);
    z--;
    garbageCondition = scanf("%[^\n]s", garbageInputs);
    getchar();

    if (z <= s && garbageCondition == 0)
    {
        printf("\n\n=============================================================================\n\n");
        printf(" Recipe name: %s\n\n Ingredients:\n", permList2[z].recipe);
        for (int u = 0; u < permList2[z].count; u++)
        {
            printf(" %d. %s %.2lf %s Rp%.0lf\n", u + 1, permList2[z].list[u].name, permList2[z].list[u].amount, permList2[z].list[u].type, permList2[z].list[u].price);
        }
        printf("\n Total cost: Rp%0.lf\n\n", permList2[z].total);
        printf("=============================================================================\n\n");
        FILE *fp4;
        char UI;
        fp4 = fopen("menu/menuViewingRecipe2.txt", "r");
        if (fp4 == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp4);
                printf("%c", UI);
            } while (!feof(fp4));
        }
        fclose(fp4);
        scanf("%[^\n]s", menuFunction);
        getchar();
        if (strcmp(menuFunction, "back") == 0)
        {
            menuPrint = 1;
            menuRecipes();
        }
        else if (strcmp(menuFunction, "end") == 0)
        {
            return 0;
        }
        else
        {
            printf("Please enter a valid input.\n");
            menuRecipes();
        }
    }
    else
    {
        menuPrint = 0;
        printf("Please enter a valid input.\n");
        menuViewingRecipe(permList2, s);
    }
}

int menuRemovingRecipes(struct recipes *permList2, int s)
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuRemovingRecipes.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    removingRecipes(permList2, s);
    menuRecipes();
}

int removingRecipes(struct recipes *permList2, int s)
{
    int z, garbageCondition;
    scanf("%d", &z);
    garbageCondition = scanf("%[^\n]s", garbageInputs);
    getchar();

    if (z <= s && z > 0 && garbageCondition == 0)
    {
        FILE *fp2;
        fp2 = fopen("data/dataRecipeList.txt", "w");
        if (fp2 == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            fprintf(fp2, "%d\n", s - 1);

            for (int t = 0; t < s - 1; t++)
            {
                if (t < z - 1)
                {
                    fprintf(fp2, "%s %u\n", permList2[t].recipe, permList2[t].count);
                    for (int u = 0; u < permList2[t].count; u++)
                    {
                        fprintf(fp2, "%s %lf %s %lf\n", permList2[t].list[u].name, permList2[t].list[u].amount, permList2[t].list[u].type, permList2[t].list[u].price);
                    }
                    fprintf(fp2, "%lf\n", permList2[t].total);
                }
                else if (t < s - 1)
                {
                    permList2[t] = permList2[t + 1];
                    fprintf(fp2, "%s %u\n", permList2[t].recipe, permList2[t].count);
                    for (int u = 0; u < permList2[t].count; u++)
                    {
                        fprintf(fp2, "%s %lf %s %lf\n", permList2[t].list[u].name, permList2[t].list[u].amount, permList2[t].list[u].type, permList2[t].list[u].price);
                    }
                    fprintf(fp2, "%lf\n", permList2[t].total);
                }
            }
        }
        fclose(fp2);
    }
    else
    {
        printf("please enter a valid input.\n");
        removingRecipes(permList2, s);
    }
}

int menuAddingRecipe()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuAddingRecipe.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    addingRecipes();
    menuRecipes();
}

int addingRecipes()
{
    FILE *fp2;
    fp2 = fopen("data/dataIngredientList.txt", "r");
    if (fp2 == 0)
    {
        printf("Unable to read file.\n");
    }
    else
    {
        int x = 0, y = -2, test = 1;
        fscanf(fp2, "%d", &x);
        struct ingredients tempList[x];
        for (int y = 0; y < x; y++)
        {
            fscanf(fp2, "%s %lf %s %lf", tempList[y].name, &tempList[y].amount, tempList[y].type, &tempList[y].price);
        }
        fclose(fp2);
        int test2 = 1, q = 0, s, totalList2 = 0;
        struct recipes tempRecipes;
        do
        {
            tempRecipes.count++;
            char tempString2[255];
            int i, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0;
            double b = 0;
            double d = 0;
            scanf("%[^\n]s", tempString2);
            getchar();
            if (strcmp(tempString2, "stop") == 0)
            {
                test2 = 0;
            }
            else
            {
                o = strlen(tempString2) - 1;
                while (tempString2[j] != '_')
                {
                    if (j == o)
                    {
                        test = 0;
                        test2 = 0;
                        printf("failed at test 1\n");
                        break;
                    }
                    j++;
                }
                k = j + 1;
                if (test)
                {
                    while (tempString2[k] != '_')
                    {
                        if (k == o)
                        {
                            test = 0;
                            test2 = 0;
                            printf("failed at test 2\n");
                            break;
                        }
                        k++;
                    }
                }
                l = k + 1;
                if (test)
                {
                    while (tempString2[l] != '\0')
                    {
                        l++;
                    }
                }
                j--;
                k--;
                l--;
                if (j + 1 < 26 && k - j + 1 < 18 && l - k + 1 < 15)
                {
                    for (i = 0; tempString2[i] != '_'; i++)
                    {
                        if ((tempString2[i] >= 'a' && tempString2[i] <= 'z'))
                        {
                            tempRecipes.list[tempRecipes.count].name[i] = tempString2[i];
                        }
                        else
                        {
                            test = 0;
                            test2 = 0;
                            printf("failed at test 3\n");
                            break;
                        }
                    }
                    if (test)
                    {
                        for (i = i + 1; tempString2[i] != '_'; i++)
                        {
                            if (tempString2[i] >= '0' && tempString2[i] <= '9')
                            {
                                long long int y = 1;
                                for (int z = 0; z < k - i; z++)
                                {
                                    y *= 10;
                                }
                                tempRecipes.list[tempRecipes.count].amount += (tempString2[i] - '0') * y;
                            }
                            else
                            {
                                test = 0;
                                test2 = 0;
                                printf("failed at test 4\n");
                                break;
                            }
                        }
                    }
                    if (test)
                    {
                        for (i = i + 1; tempString2[i] != '\0'; i++)
                        {
                            if (tempString2[i] >= 'a' && tempString2[i] <= 'z')
                            {
                                tempRecipes.list[tempRecipes.count].type[n] = tempString2[i];
                                n++;
                            }
                            else
                            {
                                test = 0;
                                test2 = 0;
                                printf("failed at test 5\n");
                                break;
                            }
                        }
                    }
                }
                else
                {
                    test = 0;
                    test2 = 0;
                    printf("failed at test 6\n");
                }
            }

            if (test2 && y != -1)
            {
                y = searchIngredients(tempList, tempRecipes, 0, x - 1, tempRecipes.count);
                if (strcmp(tempRecipes.list[tempRecipes.count].type, "grams") == 0)
                {
                    tempRecipes.list[tempRecipes.count].price = tempRecipes.list[tempRecipes.count].amount / 100 * tempList[y].price;
                    tempRecipes.total += tempRecipes.list[tempRecipes.count].price;
                }
                else if (strcmp(tempRecipes.list[tempRecipes.count].type, "ounces") == 0)
                {
                    tempRecipes.list[tempRecipes.count].price = (tempRecipes.list[tempRecipes.count].amount * 28.3495) / 100 * tempList[y].price;
                    tempRecipes.total += tempRecipes.list[tempRecipes.count].price;
                }
                else if (strcmp(tempRecipes.list[tempRecipes.count].type, "kilograms") == 0)
                {
                    tempRecipes.list[tempRecipes.count].price = (tempRecipes.list[tempRecipes.count].amount * 1000) / 100 * tempList[y].price;
                    tempRecipes.total += tempRecipes.list[tempRecipes.count].price;
                }
                else if (strcmp(tempRecipes.list[tempRecipes.count].type, "pounds") == 0)
                {
                    tempRecipes.list[tempRecipes.count].price = (tempRecipes.list[tempRecipes.count].amount * 453.592) / 100 * tempList[y].price;
                    tempRecipes.total += tempRecipes.list[tempRecipes.count].price;
                }
                else
                {
                    test = 0;
                    test2 = 0;
                    printf("failed at test 7\n");
                }
                tempRecipes.list[tempRecipes.count - 1] = tempRecipes.list[tempRecipes.count];
            }

        } while (test2);
        if (test && y != -1)
        {
            tempRecipes.count--;
            char tempName[30] = {'\0'};
            int test3 = 1;
            while (test3)
            {
                if(test){
                    printf("\n\n=============================================================================\n\n");
                    printf("==> Please input [recipe name] to store the recipe");
                    printf("\n\n=============================================================================\n\n");
                }
                scanf("%[^\n]s", tempName);
                getchar();
                for (int t = 0; tempName[t] != '\0'; t++)
                {
                    if (tempName[t] < 'a' || tempName[t] > 'z')
                    {
                        test = 0;
                        test2 = 0;
                        printf("failed at test 8\n");
                        printf("please enter a valid name.\n");
                        break;
                    }
                }
                test3 = 0;
            }
            if (test)
            {
                FILE *fp4;
                fp4 = fopen("data/dataRecipeList.txt", "r");
                if (fp4 == 0)
                {
                    printf("Unable to read file.\n");
                }
                else
                {
                    fscanf(fp4, "%d", &s);
                    totalList2 = 1 + s;
                    struct recipes permList2[totalList2];
                    for (int t = 0; t < s; t++)
                    {
                        fscanf(fp4, "%s %u", permList2[t].recipe, &permList2[t].count);
                        for (int u = 0; u < permList2[t].count; u++)
                        {
                            fscanf(fp4, "%s %lf %s %lf %lf", permList2[t].list[u].name, &permList2[t].list[u].amount, permList2[t].list[u].type, &permList2[t].list[u].price, &permList2[t].total);
                        }
                    }

                    strcpy(permList2[s].recipe, tempName);
                    permList2[s].count = tempRecipes.count;
                    for (int v = 0; v < tempRecipes.count; v++)
                    {
                        strcpy(permList2[s].list[v].name, tempRecipes.list[v].name);
                        permList2[s].list[v].amount = tempRecipes.list[v].amount;
                        strcpy(permList2[s].list[v].type, tempRecipes.list[v].type);
                        permList2[s].list[v].price = tempRecipes.list[v].price;
                        permList2[s].total = tempRecipes.total;
                    }
                    fclose(fp2);
                    fclose(fp4);
                    sortRecipes(permList2, totalList2);
                }
            }
            else
            {
                addingRecipes();
            }
        }
        else
        {
            printf("failed at test 9\n");
            printf("please enter a valid input.\n");
            test = 1;
            addingRecipes();
        }
    }
}

int searchIngredients(struct ingredients *a, struct recipes e, int l, int r, int p)
{

    int mid = l + (r - l) / 2, condition = strcmp(a[mid].name, e.list[p].name);
    if (l > r)
    {
        return -1;
    }
    if (condition == 0)
    {
        return mid;
    }
    else if (condition == 1)
    {
        return searchIngredients(a, e, l, mid - 1, p);
    }
    else
    {
        return searchIngredients(a, e, mid + 1, r, p);
    }
}

int sortRecipes(struct recipes *example, int size)
{
    merge_sort2(example, size);
    if (menuPrint)
    {
        FILE *fp;
        fp = fopen("data/dataRecipeList.txt", "w");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            fprintf(fp, "%d\n", size);
            for (int t = 0; t < size; t++)
            {
                fprintf(fp, "%s %u\n", example[t].recipe, example[t].count);
                for (int u = 0; u < example[t].count; u++)
                {
                    fprintf(fp, "%s %lf %s %lf\n", example[t].list[u].name, example[t].list[u].amount, example[t].list[u].type, example[t].list[u].price);
                }
                fprintf(fp, "%lf\n", example[t].total);
            }
        }
        fclose(fp);
        return 0;
    }
    else
    {
        printf("please input an original name\n");
        menuPrint = 1;
        addingRecipes();
    }
}

void merge_sort2(struct recipes *a, int length)
{
    merge_sort_recursion2(a, 0, length - 1);
}

void merge_sort_recursion2(struct recipes *a, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        merge_sort_recursion2(a, l, m);
        merge_sort_recursion2(a, m + 1, r);

        merge_sorted_arrays2(a, l, m, r);
    }
}

void merge_sorted_arrays2(struct recipes *a, int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    struct recipes temp_left[left_length];
    struct recipes temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = a[l + i];

    for (i = 0; i < right_length; i++)
        temp_right[i] = a[m + 1 + i];

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        if (i < left_length && (j >= right_length || z2(temp_left, temp_right, i, j)))
            a[k] = temp_left[i++];
        else
            a[k] = temp_right[j++];
    }
}

int z2(struct recipes *temp_left, struct recipes *temp_right, int i, int j)
{
    int k = strcmp(temp_left[i].recipe, temp_right[j].recipe);
    if (k == 0)
    {
        menuPrint = 0;
        return 0;
    }
    else if (k == -1)
    {
        return 1;
    }
    else if (k == 1)
    {
        return 0;
    }
}

int menuBudgetPlanner()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuBudgetPlanner.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    if (menuPrint)
    {
        FILE *fp2;
        fp2 = fopen("data/dataBudgetPlanner.txt", "r");
        if (fp2 == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            fscanf(fp2, "%lld %d", &currentBudget.budget, &currentBudget.days);
            currentBudget.allowance = (long long int)currentBudget.budget / currentBudget.days;
            printf("Your current budget is: Rp%lld\n For: %d day(s)\n", currentBudget.budget, currentBudget.days);
            printf(" Allowance per day: Rp%lld\n\n=============================================================================\n\n", currentBudget.allowance);
        }
        fclose(fp2);
    }
    scanf("%[^\n]s", menuFunction);
    getchar();
    if (strcmp(menuFunction, "add") == 0)
    {
        menuPrint = 1;
        menuAddingBudget(1);
    }
    else if (strcmp(menuFunction, "subtract") == 0)
    {
        menuPrint = 1;
        menuAddingBudget(0);
    }
    else if (strcmp(menuFunction, "cook") == 0)
    {
        menuPrint = 1;
        menuCooking(currentBudget);
    }
    else if (strcmp(menuFunction, "back") == 0)
    {
        menuPrint = 1;
        menuMain();
    }
    else if (strcmp(menuFunction, "end") == 0)
    {
        return 0;
    }
    else
    {
        menuPrint = 0;
        printf("Please enter a valid input.\n");
        menuBudgetPlanner();
    }
}

int menuAddingBudget(short condition)
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuAddingBudget.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    addingBudget(condition);
    menuBudgetPlanner();
}
int addingBudget(short condition)
{
    char tempString[105];
    int i, test = 1, j = 0, k = 0, d = 0;
    long long int b = 0;
    scanf("%s", tempString);
    getchar();
    while (tempString[j] != '_')
    {
        j++;
    }
    j--;
    while (tempString[k] != '\0')
    {
        k++;
    }
    k--;
    if (j + 1 < 18 && k - j + 1 < 8)
    {
        for (i = 0; tempString[i] != '_'; i++)
        {
            if (tempString[i] >= '0' && tempString[i] <= '9')
            {
                long long int y = 1;
                for (int z = 0; z < j - i; z++)
                {
                    y *= 10;
                }
                b += (tempString[i] - '0') * y;
            }
            else
            {
                test = 0;
                break;
            }
        }

        for (i = i + 1; tempString[i] != '\0'; i++)
        {
            if (tempString[i] >= '0' && tempString[i] <= '9')
            {
                long long int y = 1;
                for (int z = 0; z < k - i; z++)
                {
                    y *= 10;
                }
                d += (tempString[i] - '0') * y;
            }
            else
            {
                test = 0;
                break;
            }
        }
    }
    else
    {
        test = 0;
    }
    if (test)
    {
        FILE *fp;
        fp = fopen("data/dataBudgetPlanner.txt", "w");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            if (condition)
            {
                currentBudget.budget += b;
                currentBudget.days += d;
                fprintf(fp, "%lld %d\n", currentBudget.budget, currentBudget.days);
                fclose(fp);
            }
            else
            {
                currentBudget.budget -= b;
                currentBudget.days -= d;
                fprintf(fp, "%lld %d\n", currentBudget.budget, currentBudget.days);
                fclose(fp);
            }
        }
    }
    else
    {
        printf("Please enter a valid input\n");
        addingBudget(condition);
    }
}

long long int menuCooking(struct budget currentBudget)
{
    long long int tempBudget = currentBudget.allowance;
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuCooking.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    FILE *fp4;
    fp4 = fopen("data/dataRecipeList.txt", "r");
    if (fp4 == 0)
    {
        printf("Unable to read file.\n");
    }
    else
    {
        int s = 0, condition2 = 1;
        fscanf(fp4, "%d", &s);
        struct recipes permList2[s];
        for (int t = 0; t < s; t++)
        {
            fscanf(fp4, "%s %u", permList2[t].recipe, &permList2[t].count);
            for (int u = 0; u < permList2[t].count; u++)
            {
                fscanf(fp4, "%s %lf %s %lf %lf", permList2[t].list[u].name, &permList2[t].list[u].amount, permList2[t].list[u].type, &permList2[t].list[u].price, &permList2[t].total);
            }
        }
        fclose(fp4);
        int z, garbageCondition = 0;
        scanf("%d", &z);
        garbageCondition = scanf("%[^\n]s", garbageInputs);
        getchar();
        if (z <= 10e7 && z > 0 && garbageCondition == 0)
        {
            for (int i = 0; i < z; i++)
            {
                int option = 0;
                int y;
                if (menuPrint)
                {
                    printf("Recipes that meet your daily allowance:\n");
                }
                for (int u = 0; u < s; u++)
                {
                    if (currentBudget.allowance > permList2[u].total && menuPrint)
                    {
                        printf("\n%d. %s Rp%.0lf", option + 1, permList2[u].recipe, permList2[u].total);
                        option++;
                    }
                }
                if (menuPrint)
                {
                    printf("\n\n=============================================================================\n\n");
                    printf("==> Please input [recipe name] to cook that recipe");
                    printf("\n\n=============================================================================\n\n");
                }
                char tempRecipeName[255] = {'\0'};
                scanf("%[^\n]s", tempRecipeName);
                getchar();
                if (strcmp(tempRecipeName, "stop") == 0)
                {
                    condition2 = 0;
                }
                if (condition2)
                {
                    y = searchRecipes(permList2, tempRecipeName, 0, s - 1);
                    if (y != -1)
                    {
                        currentBudget.allowance -= permList2[y].total;
                        menuPrint = 1;
                        if (currentBudget.allowance <= 0)
                        {
                            printf("Error: you are spending too much.\n");
                            i = z;
                            condition2 = 0;
                        }
                    }
                    else
                    {
                        i--;
                        printf("Please input a valid name.\n");
                        menuPrint = 0;
                    }
                }
            }
            if (condition2)
            {
                FILE *fp2;
                fp2 = fopen("data/dataBudgetPlanner.txt", "w");
                if (fp2 == 0)
                {
                    printf("Unable to read file.\n");
                }
                else
                {
                    currentBudget.budget -= tempBudget - currentBudget.allowance;
                    fprintf(fp2, "%lld %d\n", currentBudget.budget, currentBudget.days - 1);
                    fclose(fp2);
                }
                menuPrint = 1;
                menuBudgetPlanner();
            }
        }
        else
        {
            menuPrint = 0;
            printf("Please enter a valid input.\n");
            menuCooking(currentBudget);
        }
    }
}

int searchRecipes(struct recipes *a, char *tempRecipeName, int l, int r)
{

    int mid = l + (r - l) / 2, condition = strcmp(a[mid].recipe, tempRecipeName);
    if (l > r)
    {
        return -1;
    }
    if (condition == 0)
    {
        return mid;
    }
    else if (condition == 1)
    {
        return searchRecipes(a, tempRecipeName, l, mid - 1);
    }
    else
    {
        return searchRecipes(a, tempRecipeName, mid + 1, r);
    }
}

int menuMain()
{
    if (menuPrint)
    {
        FILE *fp;
        char UI;
        fp = fopen("menu/menuMain.txt", "r");
        if (fp == 0)
        {
            printf("Unable to read file.\n");
        }
        else
        {
            do
            {
                UI = getc(fp);
                printf("%c", UI);
            } while (!feof(fp));
        }
        fclose(fp);
    }
    int z, garbageCondition;
    scanf("%d", &z);
    garbageCondition = scanf("%[^\n]s", garbageInputs);
    getchar();

    if (z <= 4 && z > 0 && garbageCondition == 0)
    {
        switch (z)
        {
        case 1:
            menuPrint = 1;
            menuIngredientList();
            break;

        case 2:
            menuPrint = 1;
            menuRecipes();
            break;

        case 3:
            menuPrint = 1;
            menuBudgetPlanner();
            break;

        case 4:
            return 0;
            break;
        }
    }
    else
    {
        menuPrint = 0;
        printf("Please enter a valid input.\n");
        menuMain();
    }
}
