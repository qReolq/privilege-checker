#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
#include <windows.h>
#include <lm.h>

using namespace std;

wstring convertStringToWString(const string& str) {
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        return 1;
    }

    string username = argv[1];
    wstring usernameWStr = convertStringToWString(username);
    LPCWSTR usernameLPC = usernameWStr.c_str();

    USER_INFO_2* buffer = nullptr;

    NET_API_STATUS status = NetUserGetInfo(
        NULL,
        usernameLPC,
        2,
        reinterpret_cast<LPBYTE*>(&buffer)
    );

    if (buffer == NULL) {
        cout << "User not found";
        return 0;
    }

    switch (buffer[0].usri2_priv) {
        case USER_PRIV_GUEST:
            cout << "GUEST" << endl;
            break;
        case USER_PRIV_USER:
            cout << "USER" << endl;
            break;
        case USER_PRIV_ADMIN:
            cout << "ADMIN" << endl;
            break;
    }

    return 0;
}
