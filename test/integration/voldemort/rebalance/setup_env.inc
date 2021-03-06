# set up the common variables
# may need to consolidate later

set +x
# figure out the basedir and voldemort dir
REBALANCE_TEST_DIR=`dirname $0`
REBALANCE_TEST_DIR=`(cd $REBALANCE_TEST_DIR&& pwd)`
cd $REBALANCE_TEST_DIR
REBALANCE_TEST_DIR=`(cd $REBALANCE_TEST_DIR&& pwd)`

VLDMDIR=`dirname $0`/../../../..
VLDMDIR=`(cd $VLDMDIR && pwd)`
cd $VLDMDIR
VLDMDIR=`(cd $VLDMDIR && pwd)`

cd $REBALANCE_TEST_DIR
TESTCFG_PREFIX=$REBALANCE_TEST_DIR/config/test_config
TESTCFG_DIR=$REBALANCE_TEST_DIR/test_config
ORIGCFG_DIR=$REBALANCE_TEST_DIR/config
WORKDIR=$REBALANCE_TEST_DIR
METADIR=$REBALANCE_TEST_DIR/metadata
TMPCLUSTER=$WORKDIR/tmpcluster
LOGDIR=$WORKDIR/log
DATADIR=$WORKDIR/data
vldm_dir=$VLDMDIR
work_dir=$REBALANCE_TEST_DIR
REMOTEUSER=hadoop
DATASOURCE=/raid10/DONT-REMOVE/test_config
REMOTEVLD=/home/hadoop/voldemort
REMOTEWORK=$REMOTEVLD/test/integration/voldemort/rebalance

# set up the remote run
# expect remote server to have the same structure
#NUMS_TO_KILL_OR_SUSPEND=$(($RANDOM%$TOTAL_NUM_SERVERS+1))
NUMS_TO_KILL_OR_SUSPEND=1
REMOTE_RUN=true
TOTAL_NUM_SERVERS=6
TOTAL_OLD_SERVERS=4
# note: list old servers first, then the new servers.
#SERVER_MACHINES=(localhost localhost localhost)
SERVER_MACHINES=(miner12.qa.linkedin.com miner13.qa.linkedin.com miner14.qa.linkedin.com miner15.qa.linkedin.com miner16.qa.linkedin.com miner17.qa.linkedin.com)
SERVER_PORT=(6667 6669 6671 6673 6675 6677)
KILLMODE="STEALER-ONLY"
#KILLMODE="NONE"
GENERATE_CLUSTER="FALSE"

set -x

