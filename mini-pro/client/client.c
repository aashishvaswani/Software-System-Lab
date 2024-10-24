#include "customer_client.c"
#include "employee_client.c"
#include "admin_client.c"

int connect_server()
{
    struct sockaddr_in server_address;
    int socket_fd;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0)
        return -1;

    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        return -1;

    return socket_fd;
}

int main()
{
    int socket_fd = connect_server();

    if (socket_fd == -1)
    {
        perror("❌💥 Connection failed! Server not reachable.");
        exit(EXIT_FAILURE);
    }

    char username[USERNAME_SIZE], password[PASSWORD_SIZE];
    Token *user = (Token *)malloc(sizeof(Token));
    int user_type;

    user->user_id = -1;

    printf("\n✨🏦 Welcome to **Mumbai Local Bank!** 🏦✨\n");
    printf("🔐 **LOGIN PORTAL** 🔐\n");
    printf("------------------------------------\n");
    printf("1️⃣ 👛 **CUSTOMER** (Access your funds)\n");
    printf("2️⃣ 🛠️ **EMPLOYEE** (Manage accounts)\n");
    printf("3️⃣ 👑 **ADMIN** (Control everything)\n");
    printf("🛑 Press any other key to exit.\n");
    printf("------------------------------------\n");

    printf("➡️ Please select your user type: ");
    scanf("%d", &user_type);

    if (user_type < 1 || user_type > 3) {
        printf("👋 Thank you for visiting! See you next time. 🌟\n");
        close(socket_fd);
        return 0;
    }

    printf("\n🧑 Enter the Username: ");
    scanf("%s", username);
    printf("🔑 Enter the Password: ");
    scanf("%s", password);

    if (login(socket_fd, user, username, password, (UserType)user_type) < 0) {
        printf("❌ Incorrect credentials! Please try again.\n");
        return -1;
    }

    if (user->user_id == -1) {
        printf("🚫 Access denied! Invalid user.\n");
        return -1;
    }

    printf("✅ Login successful! Welcome aboard 🎉\n");

    switch (user_type)
    {
        case CUSTOMER:
            printf("👛 Welcome, Valued Customer! 💳💼\n");
            printf("-----------------------------\n");
            customer_handler(socket_fd, user);
            break;

        case EMPLOYEE:
            printf("🛠️ Welcome, Hardworkers! 💼📊\n");
            printf("-----------------------------\n");
            employee_handler(socket_fd, user);
            break;

        case ADMIN:
            printf("👑 Welcome, Mighty Admin! 🎯🔧\n");
            printf("-----------------------------\n");
            admin_handler(socket_fd, user);
            break;

        default:
            break;
    }

    printf("🚪 Logging out... Goodbye! ✨👋\n");
    close(socket_fd);
    return 0;
}
