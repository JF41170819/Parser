typedef struct
{
    char domain[500];
    char ip[250];
    char userName[500];
    char email[500];
    char startDate[250];
    char diskPartition[250];
    int quota;
    int diskSpaceUsed;
    char package[500];
    char theme[500];
    char owner[250];
    char server[500];
    char unixStartDate[500]; //int
    long long int diskSpaceUsedBytes;
    long long int quotaBytes;
    int isSuspended;
    char suspensionDate[250];
    char suspensionLocked[250];
    char suspensionReason[250];

}ePersona;
