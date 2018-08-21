set platform=%1
set configuration=%2

@echo PLATFORM      %PLATFORM%
@echo CONFIGURATION %CONFIGURATION%
@echo.

@echo ---- start build-sln.bat ----
call build-sln.bat       %PLATFORM% %CONFIGURATION% || (echo error build-sln.bat       && exit /b 1)
@echo ---- end   build-sln.bat ----
@echo.

@echo ---- start build-chm.bat ----
call build-chm.bat                                  || (echo error build-chm.bat       && exit /b 1)
@echo ---- end   build-chm.bat ----
@echo.

@echo ---- start build-installer.bat ----
call build-installer.bat %PLATFORM% %CONFIGURATION% || (echo error build-installer.bat && exit /b 1)
@echo ---- end   build-installer.bat ----
@echo.

@echo ---- start externals\cppcheck\install-cppcheck.bat ----
call externals\cppcheck\install-cppcheck.bat        || (echo error externals\cppcheck\install-cppcheck.bat && exit /b 1)
@echo ---- end   externals\cppcheck\install-cppcheck.bat ----
@echo.

@echo ---- start run-cppcheck.bat ----
call run-cppcheck.bat %PLATFORM% %CONFIGURATION%    || (echo error run-cppcheck.bat    && exit /b 1)
@echo ---- end   run-cppcheck.bat ----
@echo.

@echo ---- start zipArtifacts.bat ----
call zipArtifacts.bat    %PLATFORM% %CONFIGURATION% || (echo error zipArtifacts.bat    && exit /b 1)
@echo ---- end   zipArtifacts.bat ----
@echo.

exit /b 0
