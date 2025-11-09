#include "SaveFolderFix.h"
#include <shlobj.h>
#include <iostream>
#include <string>

namespace SaveFix {
    void CreateSaveFolder() {
        PWSTR localAppDataPath = nullptr;

        // Get the LocalAppData folder path
        HRESULT hr = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &localAppDataPath);

        if (SUCCEEDED(hr)) {
            // Convert to string and append Ghostbusters folder
            std::wstring savePath = localAppDataPath;
            savePath += L"\\GHOSTBUSTERS";

            // Check if folder exists
            DWORD attribs = GetFileAttributesW(savePath.c_str());

            if (attribs == INVALID_FILE_ATTRIBUTES) {
                // Folder doesn't exist, create it
                if (CreateDirectoryW(savePath.c_str(), NULL)) {
                    MessageBoxW(NULL, L"Ghostbusters save folder created successfully!",
                        L"Save Fix", MB_OK | MB_ICONINFORMATION);
                }
                else {
                    DWORD error = GetLastError();
                    if (error != ERROR_ALREADY_EXISTS) {
                        MessageBoxW(NULL, L"Failed to create Ghostbusters save folder!",
                            L"Save Fix Error", MB_OK | MB_ICONERROR);
                    }
                }
            }

            // Free the memory allocated by SHGetKnownFolderPath
            CoTaskMemFree(localAppDataPath);
        }
        else {
            MessageBoxW(NULL, L"Failed to get LocalAppData path!",
                L"Save Fix Error", MB_OK | MB_ICONERROR);
        }
    }
}
