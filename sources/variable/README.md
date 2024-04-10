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
```