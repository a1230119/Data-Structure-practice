Binary Search Tree

1. OS : Win8.1
2. �{���y�� : C

<search>

�M��k�O�_�w�btree��
�����ܦ^�ǸӸ`�I�A�Y�S���h�^��k�N�ӥi���J�b���Ӹ`�I���U

<insert>

�M��node�i���J�b���Ӹ`�I���U

<printp>

�L�Xdata�A�Y�O�Ÿ`�I�h�L�X*

<delet>

�R���`�I
1.�Y�Ӹ`�I�Oleaf(!(ptr->leftChild) && !(ptr->rightChild))=>�����R��
2.�Y�䥪�l�𬰪�(!(ptr->leftChild))=>�Ϩ�k�`�I�������N��
3.�Y��k�l�𬰪�(!(ptr->rightChild))=>�Ϩ䥪�`�I�������N��
4.�Y���k�l��ҫD��=>�Ϩ䥪�l�𤧳̤j�Ȳ��ܸӦ�m

<main>
1.���ϥ�do-while�j���Jdata
2.�A�ϥ�insert��Ҧ��`�I���W
3.��tree�̧ǩ�Jqueue�̡A�æP�ɥΤ@���r�ӭp�ơAdata���Ȯ�r+1
  ��r=input���ƶq�ɪ�����queue�̪��F��L�X��
4.���t�Mpow(2,t)�ΨӨM�w��ɴ���
5.�ϥ�for�j��ѨϥΪ̧R���`�I�A�䤤�Υ��L��check�P�_��J�ȬO�_�Atree��
  ����ϥΪ̤��R���`�I�~���X�j��A�����{��

<time complexity>...h��binary search tree������
1.search:O(h)�A�]���C��@�h�P�_�@���j�p�A�̦h�o�g�Lh�h
2.insert:O(h)�A�]���n���j�M��A�Ѿl�������O�K(1)
3.printp:�K(1)
4.delet:O(h)�A�C�R���@�Ӹ`�I�A�n�N�U���������W���@�h�A�̦h�|��h��