#include "validation.hpp"

#include <ctype.h>

#include <algorithm>

constexpr int minPasswordLength = 9;

std::string getErrorMessage(const ErrorCode errorText) {
    switch (errorText) {
    case ErrorCode::Ok:
        return "Ok";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password Needs At Least Nine Charackters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password Needs At Least One Number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password Needs At Least One Special Charackter";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password Needs At Least One Uppercase Letter";
    case ErrorCode::PassowodDoesNotMatch:
        return "Password Does Not Match";
    default:
        return "Unknown Error";
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < minPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(password.begin(), password.end(), ::ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (!doesPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::PassowodDoesNotMatch;
    }

    return checkPasswordRules(password);
}