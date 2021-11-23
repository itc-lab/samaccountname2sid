# sAMAccountName2SID

nametosid.exe is a command line exe to convert User/Group Name(sAMAccountName) to SID and display it.

## Technologies

Project is created with:

- Visual Studio Community 2019

## Build

Clone this repository.
![Clone this repository](https://user-images.githubusercontent.com/76575923/142963708-ca2dacf6-5793-4a50-bb6c-5ee99008b09d.png)|
|:-:|

Open `nametosid.sln`.
![Open nametosid.sln](https://user-images.githubusercontent.com/76575923/142963802-bc3e9014-ff77-4903-9ad4-a97f48b53fda.png)|
|:-:|

Run "Build nametosid".
![Build1](https://user-images.githubusercontent.com/76575923/142963838-0f84d392-c08e-42aa-81e4-0562975eb33a.png)|
|:-:|

| ![Build2](https://user-images.githubusercontent.com/76575923/142963858-df003000-360b-49d6-962b-0472463074cb.png) |
| :--------------------------------------------------------------------------------------------------------------: |

## Usage

```
nametosid <user>@<AD domain>
```

## Example

```
>nametosid ad.contoso.com\foobar
S-1-5-21-312109860-4223824132-3422679046-73503

>nametosid ad\foobar
S-1-5-21-312109860-4223824132-3422679046-73503

>nametosid foobar@ad.contoso.com
S-1-5-21-312109860-4223824132-3422679046-73503

>nametosid foobar@ad
S-1-5-21-312109860-4223824132-3422679046-73503
```
