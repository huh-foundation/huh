# Variable

"huh" automatically infers the characteristics of a variable based on the naming convention.

You can define and use the variable in the form of "the <variable name>".

For example, a variable written in camel-case will automatically have mutable characteristics.

### Example

```
the userNickname = "USER"
userNickname = "USER1"

the UserNickname = "USER"
// UserNickname = "USER1" error: Variables written in Pascal case cannot be reassigned.

the user_name = "USER"
user_name = "USER1"
```

<br>

## Convention inference


Convention inference is designed as follows, and certain characteristics are determined when variables are created using the following convention.

convention | characteristic
---|---
camelCase | Variable
PascalCase | Constant
snake_case | Variable
Screaming_Snake_Case | Constant
UPPERCASE | Constant
kebab-case | Variable

