#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char label[20], opcode[20], operand[20];
    char code[20], value[20], sym[20], addr[20];
    char obj_code[20], t_record[80] = "", prog_name[20];
    int loc, start_addr = 0, length = 0, last_addr = 0;
    int t_start_addr = 0, t_len = 0;
    FILE *inter = fopen("intermediate.txt", "r");
    FILE *optab = fopen("optab.txt", "r");
    FILE *symtab = fopen("symtab.txt", "r");
    FILE *prog = fopen("program.txt", "w");
    if (!inter || !optab || !symtab || !prog) {
        printf("Error: Could not open files.\n");
        return 1;
    }
    fscanf(inter, "%X %s %s %s", &loc, label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        start_addr = (int)strtol(operand, NULL, 16);
        strcpy(prog_name, label);
    }
    while (fscanf(inter, "%X %s %s %s", &last_addr, label, opcode, operand) != EOF);
    length = last_addr - start_addr;
    rewind(inter);
    fscanf(inter, "%X %s %s %s", &loc, label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
        fscanf(inter, "%X %s %s %s", &loc, label, opcode, operand);
    fprintf(prog, "H^%-6s^%06X^%06X\n", prog_name, start_addr, length);
    t_start_addr = loc;
    while (strcmp(opcode, "END") != 0) {
        strcpy(obj_code, "");
        rewind(optab);
        int found_opcode = 0;
        while (fscanf(optab, "%s %s", code, value) != EOF) {
            if (strcmp(opcode, code) == 0) {
                found_opcode = 1;
                if (strcmp(operand, "**") != 0) {
                    rewind(symtab);
                    int found_sym = 0;
                    while (fscanf(symtab, "%s %s", sym, addr) != EOF) {
                        if (strcmp(operand, sym) == 0) {
                            sprintf(obj_code, "%s%s", value, addr);
                            found_sym = 1;
                            break;
                        }
                    }
                    if (!found_sym) sprintf(obj_code, "%s0000", value);
                } else sprintf(obj_code, "%s0000", value);
                break;
            }
        }
        if (!found_opcode) {
            if (strcmp(opcode, "WORD") == 0)
                sprintf(obj_code, "%06X", atoi(operand));
            else if (strcmp(opcode, "BYTE") == 0) {
                char temp[20] = "";
                if (operand[0] == 'C') {
                    for (int i = 2; operand[i] != '\''; i++)
                        sprintf(temp + strlen(temp), "%02X", operand[i]);
                } else {
                    for (int i = 2; operand[i] != '\''; i++)
                        sprintf(temp + strlen(temp), "%c", operand[i]);
                }
                strcpy(obj_code, temp);
            }
        }
        if (strlen(obj_code) > 0) {
            if (t_len + strlen(obj_code) > 60) {
                fprintf(prog, "T^%06X^%02X%s\n", t_start_addr, t_len / 2, t_record);
                strcpy(t_record, "");
                t_len = 0;
                t_start_addr = loc;
            }
            strcat(t_record, "^");
            strcat(t_record, obj_code);
            t_len += strlen(obj_code);
        } else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
            if (t_len > 0) {
                fprintf(prog, "T^%06X^%02X%s\n", t_start_addr, t_len / 2, t_record);
                strcpy(t_record, "");
                t_len = 0;
            }
            t_start_addr = 0;
        }
        fscanf(inter, "%X %s %s %s", &loc, label, opcode, operand);
        if (t_start_addr == 0) t_start_addr = loc;
    }
    if (t_len > 0)
        fprintf(prog, "T^%06X^%02X%s\n", t_start_addr, t_len / 2, t_record);
    fprintf(prog, "E^%06X\n", start_addr);
    printf("PASS 2 completed successfully.\n");
    fclose(inter);
    fclose(optab);
    fclose(symtab);
    fclose(prog);
    return 0;
}