#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

// este codigo composto pelos comandos ls e ls -a

// O COMANDO ls -l NAO FOI IMPLEMENTADO


int main()
{
    DIR *folder;
    struct dirent *entry;
    struct stat fs;
    int files = 0;
    // quando ls_a = 0, seria o mesmo que o comando 'ls'
    // qunado ls_a = 1, seria o mesmo que o comando 'ls -a'
    int ls_a = 0; 
    int ls_l = 1;
    // insira a PASTA AQUI
    // a variavel folder É O CAMINHO DA PASTA
    folder = opendir(".");
    // checa se foi possivel abri a pasta, caso contrario RETORNA 1  
    if(folder == NULL)
    {
        perror("Não foi possível ler o diretório!");
        return(1);
    }
    // o while abaixo mostra na tela o ls
    while( (entry=readdir(folder)) )
    {
        if (entry->d_name[0] != '.' && ls_a == 0 && ls_l == 0) {
            printf("%s  ",entry->d_name);
        }
        else if (ls_a == 1 && ls_l == 0) {
            printf("%s  ",entry->d_name);
        }
        // else if (ls_a == 0 && ls_l == 1) {
        //     if (entry->d_name[0] != '.'){
        //         int r = stat(entry->d_name,&fs);
        //         if (r == -1) 
        //             printf("erro na pasta!\n");
        //         printf("%X  %s\n",fs.st_mode,entry->d_name);
        //         }
        // }
    }
    printf("\n");
    // fecha a pasta IMPORTANTE
    closedir(folder);
    // retorna 0 quando executa com sucesso
    return(0);
}