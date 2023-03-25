cmake_minimum_required(VERSION 3.21)
project(Laborator_9_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laborator_9_10 main.cpp Dulciuri.cpp Dulciuri.h Repo.cpp Repo.h Tests.cpp Tests.h Service.cpp Service.h UI.cpp UI.h FunctiiAjutatoare.cpp FunctiiAjutatoare.h RepoFile.cpp RepoFile.h Unutils/NegativePrice.h Exceptions/CantConvertToInt.h Exceptions/EmptyName.h Exceptions/EmptyCode.h Exceptions/ProductNotExist.h Exceptions/DuplicateCode.h Exceptions/InsufficientMoney.h Validators/Validator.cpp Validator.h Exceptions/NegativePrice.h Exceptions/InvalidCode.h Exceptions/IsNotNumber.h)
