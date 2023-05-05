## born2beroot
🖥️

virtual machine에 linux를 설치하고, package manager, sudo, password policy, ufw를 학습.

- ### 1) vm?
VM은 `Hypervisor` 위에서 작동한다. 하이퍼바이저가 하드웨어의 자원을 사용하여 VM을 생성하고 구동하게 된다.
- type 1 hypervisor, `Bare-metal Architecture`, 물리적인 하드웨어 위에 여러 Guest 가 설치된다.
- type 2 hypervisor, `Hosted Architecture`, 물리적인 하드웨어 위에 여러 Guest 가 설치된다.

- what is the point of using VM?
    - 가상 환경을 하나의 infra를 사용해서 구축 할 수 있기 때문에 비용 면에서 장점이있다.
    - 실제 컴퓨터를 구입하지 않아도 새로운 운영체제를 구동할 수 있다.
    - 호스트가 예기치 않게 중단될 경우 스냅샷, 백업 대책이 마련되어있다.

- ### 2) UFM (Uncomplicated Firewall)
`netfilter Module`는 네트워크 통로를 단일화해 내부 정보망을 보호하기 위한 시스템으로, 내부망과 외부망을 분리하여 접근 제어한다.

Uncomplicated Firewall은 말 그대로 복잡하지 않고 간단한 명령어로 `netfilter Module` 을 관리하는 프레임워크이다, 과제에선 `port 22`를 닫고 `port 4242`를 여는데 사용한다.
대표적으로 외부 침입자가 내부 `network`에 침입하는 경우를 막기 위해서 `UFW`를 사용한다.

- ### 3) sudo (super do, substitute user do)
	- 침입자가 `sudo`를 사용 하면 `sudoers`에 자신이 노출되기에 침입을 확인할 수 있다는 장점이 있다.
	- `root` 계정에 장시간 머무를 일이 없어져서 위험한 `command`를 실행할 가능성이 낮아진다.
	- `sudo` 사용 시에는 `log`가 남아 추적이 쉽다. `root` 계정에서 작업하면 `log`가 남지 않는다
    	- command 단위의 로그가 남아서 무분별한 root 사용보다, 더 정확한 기록을 찾을 수 있다.
	- `root`의 `password`를 타인과 공유하지 않아도 되어, 보안에 편리하다.

- ### 4) cron
특정 작업을 특정 시간에 자동으로 실행 시키기 위한 Daemon이다. crontab 이라는 설정 파일을 기반으로 작동한다.
> Daemon: 사용자의 영역에서 벗어나 Background에서 실행되고있는 프로세스를 말한다. 어원은 맥스웰의 악마로, 눈에 보이지 않고도 알아서 할 일을 다 해준다는 의미에서 명칭을 가져왔다

추가로, sudo 권한을 편집할 수 있는 `visudo`에서 `requiretty` 을 설정하는데, cron와 같은 daemon이 함부로 sudo 명령어를 실행하지 않게 하기 위한 설정이다.
