Towers of Hanoi

1. �{���������� : Win8.1
2. �{���y�� : C

<move>

���j�פ����layer=1�A�Ndisk�qA����B  =>  printf("Move disk %d from %c to %c\n", layer, A, B);

�Ө�L�h�h�i��T�ӨB�J:
1. �N�̤U�h�H�~��disks�qA����C�ɩ�@�U => move(layer-1, A, C, B);
2. �N�̤U�hdisk�qA����B => printf("Move disk %d from %c to %c\n", layer, A, B);
3. �A�N���disks�qC����B =>  move(layer-1, C, B, A);

�C���ʤ@��disk�hi�[�@�A�Ψӭp��������B�J��

<main>

scanf��Jdisk_num(disks number)
��if-else�P�_disk_number�O�_�b����ƶq(3~64)���A�Y�S���h�n�D���s��J